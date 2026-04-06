#include "musicwindow.h"
#include "ui_musicwindow.h"
#include <QDebug>
#include <QFileDialog>
#include "common/common.h"
#include <QMessageBox>
#include "music.h"
#include "musicdao.h"
#include <QtSql/QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTemporaryFile>

MusicWindow::MusicWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    this->initMusicWin();
}

MusicWindow::~MusicWindow()
{
    delete ui;
}

void MusicWindow::initMusicWin()
{
    // 初始化时间标签
    ui->label_currentTime->setText("00:00");
    ui->label_totalTime->setText("/00:00");

    //给播放按钮设置一个属性mode=(play/pause)
    //播放按钮就应该有一个默认的mode属性值
    ui->btn_play->setProperty("mode","pause");

    //给声音按钮设置一个默认的mode属性值
    ui->btn_volume->setProperty("mode","unmute");

    //初始化本地播放器与列表容器
    this->playlist=new QList<QUrl>();
    this->player=new QMediaPlayer(this);
    this->audioOutput=new QAudioOutput(this);
    this->player->setAudioOutput(audioOutput);

    // 初始化在线播放器与列表容器
    this->onlinePlaylist = new QList<QUrl>();
    this->onlineLrcList = new QList<QUrl>();
    this->onlinePlayer = new QMediaPlayer(this);
    // 可以复用同一个 audioOutput，或者新建一个：
    this->onlineAudioOutput = new QAudioOutput(this);
    this->onlinePlayer->setAudioOutput(onlineAudioOutput);

    // 连接拖动状态信号
    connect(ui->progressSlider, &QSlider::sliderPressed, this, [this]() { isDragging = true; });
    connect(ui->progressSlider, &QSlider::sliderReleased, this, [this]() { isDragging = false; });
    //给QMediaPlayer绑定信号和槽函数，去计算进度条
    connect(this->player,&QMediaPlayer::durationChanged,this,&MusicWindow::durationChanged);
    connect(this->player,&QMediaPlayer::positionChanged,this,&MusicWindow::positionChanged);
    connect(this->onlinePlayer, &QMediaPlayer::durationChanged, this, &MusicWindow::durationChanged);
    connect(this->onlinePlayer,&QMediaPlayer::positionChanged,this,&MusicWindow::positionChanged);

    // 绑定播放进度信号到歌词同步函数
    connect(this->player, &QMediaPlayer::positionChanged, this, &MusicWindow::updateLyrics);
    connect(this->onlinePlayer, &QMediaPlayer::positionChanged, this, &MusicWindow::updateLyrics);


    // 查询数据库并缓存音乐列表（包含lrc_path）
    MusicDao musicDao;
    musicList = musicDao.queryMusics(); // 获取带lrc_path的Music对象列表
    for (const Music &music : musicList) {
        playlist->append(QUrl::fromLocalFile(music.path())); // 加载歌曲路径
        ui->list_local->addItem(music.name()); // 加载歌曲名
    }
    if (!musicList.isEmpty()) {
        currentIndex = 0;
        ui->list_local->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));
        const Music &currentMusic = musicList[currentIndex]; // 获取带lrc_path的Music对象

        // 使用数据库中的lrc_path，而非动态生成
        QString lrcPath = currentMusic.lrcPath(); // 直接获取数据库存储的路径
        parseLrc(lrcPath); // 解析LRC文件（无需修改parseLrc函数）
    }

    //初始化在线列表
    this->initOnlineList();
}


//tab改变
void MusicWindow::on_tabWidget_currentChanged(int index)
{
    currentTab=index;
    if(currentTab==0){
        this->onlinePlayer->pause();
        ui->progressSlider->setValue(0);
        // 初始化时间标签
        ui->label_currentTime->setText("00:00");

    }else{
        this->player->pause();
        ui->progressSlider->setValue(0);
        // 初始化时间标签
        ui->label_currentTime->setText("00:00");
    }
    ui->btn_play->setProperty("mode","pause");
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();

    qDebug()<<currentTab;


}
//临时下载在线歌词并调用解析歌词函数
void MusicWindow::tempDownloadOnlineLrc()
{
    qDebug() << "请求 LRC 的 URL:" << onlineLrcList->at(onlineCurrentIndex).toString();
    //下载并写临时lrc文件
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *rep = manager->get(QNetworkRequest(onlineLrcList->at(onlineCurrentIndex)));
    connect(rep, &QNetworkReply::finished, this, [this, rep]() {
        if (rep->error() == QNetworkReply::NoError) {//检查请求有没有出错，只有“没有错误”（NoError）时才继续处理歌词
            QByteArray lrcData = rep->readAll();//把服务器返回的所有数据一次性读到内存中的字节数组 lrcData
            qDebug()<<"歌词data:"<<QString(lrcData)<<"歌词数据大小:"<<lrcData.size();
            QTemporaryFile tmp;                 //创建一个 QTemporaryFile 对象，用来在系统临时目录中写一个临时文件
            tmp.setFileTemplate(QString(PROJECT_SOURCE_DIR)+"/tempXXXXXX.lrc");//设置临时文件名模板，“XXXXXX” 会被替换成随机字符，保证文件名唯一
            if (tmp.open()) {
                tmp.write(lrcData);
                tmp.flush();
                qDebug()<<"临时文件路径"<<tmp.fileName();
                parseLrc(tmp.fileName());      // 用原 parseLrc 解析,传入临时文件的完整路径
                updateLyrics(0);               // 立刻刷新第一句歌词
            }
        }
        rep->deleteLater();
    });
}

void MusicWindow::initOnlineList()
{
    // 向后端服务器发起http请求
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    manager->get(QNetworkRequest(QUrl("http://localhost/music_test.json")));
    connect(manager,&QNetworkAccessManager::finished,this,&MusicWindow::showOnlineList);
}

void MusicWindow::showOnlineList(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    // 解析json
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray array = doc.array();
    if(!array.isEmpty()){
        for(int i=0;i<array.size();i++)
        {
            QJsonObject obj = array.at(i).toObject();
            QString name = obj.value("name").toString();
            QString path = obj.value("path").toString();
            QString lrc_path = obj.value("lrc_path").toString();
            ui->list_online->addItem(name);
            // 这个地方加入播放列表的时候,不能和本地列表的音乐列表混为一谈
            onlinePlaylist->append(QUrl(path));
            onlineLrcList->append(QUrl(lrc_path));
            qDebug()<<onlineLrcList->at(i);
        }
        onlineCurrentIndex=0;
        ui->list_online->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex));
        tempDownloadOnlineLrc();
    }
}

//退出
void MusicWindow::on_btn_quit_clicked()
{
    this->parentWidget()->show();
    this->hide();
}
// 毫秒转 "分:秒" 格式
QString MusicWindow::msecToTime(qint64 msec) {
    if (msec <= 0) return "00:00"; // 处理无效时间

    int sec = msec / 1000;          // 总秒数
    int min = sec / 60;             // 分钟
    sec %= 60;                      // 剩余秒数

    // 格式化为两位数（不足补0）
    return QString("%1:%2").arg(min, 2, 10, QChar('0'))
        .arg(sec, 2, 10, QChar('0'));
}

//保持当前的播放状态
void MusicWindow::keepStatus()
{
    QString mode=ui->btn_play->property("mode").toString();
    int newIndex=ui->list_local->currentRow();  //有可能单击选中歌曲索引改变
    int onlineNewIndex=ui->list_online->currentRow();
    if(currentTab==0){
        if(mode=="pause"){//保持之前的播放形式
            if(currentIndex!=newIndex){ //与新索引不等
                ui->btn_play->setProperty("mode","pause");
                this->player->pause();
                currentIndex=newIndex;
                player->setSource(playlist->at(currentIndex));//换源
            }else{
                ui->btn_play->setProperty("mode","pause");
                this->player->pause();
            }
        }else{//如果是播放保持播放状态
            ui->btn_play->setProperty("mode","play");
            playAtIndex(currentIndex);
        }
    }else{
        if(mode=="pause"){//保持之前的播放形式
            if(onlineCurrentIndex!=onlineNewIndex){
                ui->btn_play->setProperty("mode","pause");
                this->onlinePlayer->pause();
                onlineCurrentIndex=onlineNewIndex;
                onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex));
            }else{
                ui->btn_play->setProperty("mode","pause");
                this->onlinePlayer->pause();
            }
        }else{
            ui->btn_play->setProperty("mode","play");
            playAtIndex(onlineCurrentIndex);
        }
    }
    // 同步刷新按钮样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();

}

//播放当前索引歌曲
void MusicWindow::playAtIndex(int index)
{
    if(currentTab==0){          //本地
        if(index>=0&&index<playlist->size()){
            currentIndex=index;
            player->setSource(playlist->at(currentIndex));

            const Music &currentMusic = musicList[currentIndex]; // 获取带lrc_path的Music对象
            //加载同名LRC文件（假设歌曲和LRC文件名相同，扩展名不同）
            // QString songPath = playlist->at(currentIndex).toLocalFile();
            // QString lrcPath = songPath.section('.', 0, -2) + ".lrc"; // 替换扩展名.mp3为.lrc
            // parseLrc(lrcPath); // 解析LRC文件

            // 使用数据库中的lrc_path，而非动态生成
            QString lrcPath = currentMusic.lrcPath(); // 直接获取数据库存储的路径
            parseLrc(lrcPath); // 解析LRC文件（无需修改parseLrc函数）

            // 重置时间显示（新歌加载时）
            ui->label_currentTime->setText("00:00");
            ui->label_totalTime->setText("/00:00"); // 总时长在 durationChanged 中更新

            this->player->play();
        }
    }else{                  //在线
        if(index>=0&&index<onlinePlaylist->size()){
            onlineCurrentIndex=index;
            onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex));
            tempDownloadOnlineLrc();
            this->onlinePlayer->play();
        }
    }

}

/**
 * @brief MusicWindow::on_btn_play_clicked
 * 如果当前btn_play的mode的值是pause,点击之后就应该变为play
 * 反之亦然
 */
void MusicWindow::on_btn_play_clicked()
{
    QString mode=ui->btn_play->property("mode").toString();
    int newIndex=ui->list_local->currentRow();
    int onlineNewIndex=ui->list_online->currentRow();
    if(currentTab==0){
        if(mode=="pause"){//如果当前属性是暂停，点击后属性是播放
            if(currentIndex!=newIndex){
                currentIndex=newIndex;
                ui->btn_play->setProperty("mode","play");
                playAtIndex(currentIndex);//播放当前索引歌曲
            }else{
                ui->btn_play->setProperty("mode","play");
                this->player->play();

            }
        }else{//如果当前属性是播放，点击后属性是暂停
            ui->btn_play->setProperty("mode","pause");
            this->player->pause();
        }
    }else{
        if(mode=="pause"){//如果当前属性是暂停，点击后属性是播放
            if(onlineCurrentIndex!=onlineNewIndex){
                onlineCurrentIndex=onlineNewIndex;
                ui->btn_play->setProperty("mode","play");
                playAtIndex(onlineNewIndex);
            }else{
                ui->btn_play->setProperty("mode","play");
                this->onlinePlayer->play();
            }
        }else{//如果当前属性是播放，点击后属性是暂停
            ui->btn_play->setProperty("mode","pause");
            this->onlinePlayer->pause();
        }

    }
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();
    mode=ui->btn_play->property("mode").toString();
    qDebug()<<mode;
}

//添加本地音乐
void MusicWindow::on_btn_file_clicked()
{
    if(currentTab==1){
        // 弹窗提示
        QMessageBox::warning(
            this,
            "警告",
            QString("请回到本地列表添加歌曲"),
            QMessageBox::Ok);
        return;
    }
    QStringList files=QFileDialog::getOpenFileNames(
        this,
        "选择音乐文件",
        getProjectMusicPath(),
        "Audios(*.mp3 *.wav *.flac)");
    MusicDao musicDao;
    int addedCount = 0; // 统计新增数量

    for (const QString &filePath : files) {
        QFileInfo fileInfo(filePath);
        QString songName = fileInfo.fileName();
        QString lrcPath = fileInfo.absolutePath() + "/" + fileInfo.completeBaseName() + ".lrc";
        Music music(0, songName, filePath, lrcPath);

        // 通过数据库去重（权威数据源）
        if (musicDao.existsByPath(filePath)) {
            // 弹窗提示已存在（带文件名）
            QMessageBox::warning(
                this,
                "歌曲已存在",
                QString("《%1》已存在于本地音乐库！").arg(songName),
                QMessageBox::Ok);
            continue; // 跳过已存在的歌曲
        }

        // 插入数据库（带错误处理）
        if (!musicDao.insertMusic(music)) {
            QMessageBox::critical(
                this,
                "添加失败",
                QString("《%1》插入数据库失败：%2")
                    .arg(songName)
                    .arg(musicDao.lastError()), // 新增错误信息获取
                QMessageBox::Ok);
            continue;
        }

        // 成功添加到播放列表和UI
        playlist->append(QUrl::fromLocalFile(filePath));
        ui->list_local->addItem(songName);
        addedCount++;
    }

    // 批量添加成功提示
    if (addedCount > 0) {
        QMessageBox::information(
            this,
            "添加完成",
            QString("成功添加 %1 首歌曲！").arg(addedCount),
            QMessageBox::Ok);
    }
}

//双击本地播放歌曲
void MusicWindow::on_list_local_itemDoubleClicked(QListWidgetItem *item)
{
    //获取选中的当前索引，并播放当前歌曲
    currentIndex=ui->list_local->currentRow();
    playAtIndex(currentIndex);
    ui->btn_play->setProperty("mode","play");
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();
}

//双击在线播放歌曲
void MusicWindow::on_list_online_itemDoubleClicked(QListWidgetItem *item)
{
    //获取选中的当前索引，并播放当前歌曲
    onlineCurrentIndex=ui->list_online->currentRow();
    playAtIndex(onlineCurrentIndex);
    ui->btn_play->setProperty("mode","play");
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();

}
//移动到前一首歌曲
void MusicWindow::on_btn_pre_clicked()
{
    if(currentTab==0){
        //本地播放列表非空就播放前一首，如果是第一首，它的前一首就是最后一首
        if(playlist->isEmpty()) return;
        currentIndex=(currentIndex-1+playlist->size())%playlist->size();
        ui->list_local->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));      //换源
        qDebug()<<"本地索引"<<currentIndex;
    }else{
        //在线播放列表非空就播放前一首
        if(onlinePlaylist->isEmpty()) return;
        onlineCurrentIndex=(onlineCurrentIndex-1+onlinePlaylist->size())%onlinePlaylist->size();
        ui->list_online->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex)); //换源
        qDebug()<<"在线索引"<<onlineCurrentIndex;
    }
    //保持播放状态
    keepStatus();

}

//移动到后一首歌曲
void MusicWindow::on_btn_next_clicked()
{
    if(currentTab==0){
        //播放列表非空就播放后一首，如果是最后一首，它的后一首就是第一首
        if(playlist->isEmpty()) return;
        currentIndex=(currentIndex+1)%playlist->size();
        ui->list_local->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));      //换源
        qDebug()<<"本地索引"<<currentIndex;
    }else{
        //播放列表非空就播放后一首，如果是最后一首，它的后一首就是第一首
        if(onlinePlaylist->isEmpty()) return;
        onlineCurrentIndex=(onlineCurrentIndex+1)%onlinePlaylist->size();
        ui->list_online->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex)); //换源
        qDebug()<<"在线索引"<<onlineCurrentIndex;
    }
    //保持播放状态
    keepStatus();

}
//获取的是当前播放歌曲的总长度
void MusicWindow::durationChanged(qint64 duration)
{
    if(currentTab==0){
        this->total=duration;
    }else { // 在线Tab
        onlineTotal = duration;
    }
    // 显示总时间（如 04:02）
    ui->label_totalTime->setText("/"+msecToTime(duration));
}

//获取当前歌曲的播放位置
void MusicWindow::positionChanged(qint64 position)
{
    if (isDragging) return; // 拖动时跳过自动更新
    // 显示当前时间（如 01:49）
    ui->label_currentTime->setText(msecToTime(position));

    // 根据Tab获取对应总时长
    qint64 finalTotal = (currentTab == 0) ? this->total : onlineTotal;

    //在歌曲切换的时候，在一段时间内，this->total可能是为0，作分母会报错
    if(finalTotal>0){
        //先乘以100，要不然int相除可能为0
        int value=position*100/finalTotal;
        qDebug()<<"总长度："<<finalTotal<<" 当前："<<position<<"进度"<<value;
        ui->progressSlider->setValue(value);
    }
}

//通过进度滑动条控制播放歌曲进度
void MusicWindow::on_progressSlider_sliderReleased()
{
    int value = ui->progressSlider->value();
    qint64 position = 0;
    // 根据当前激活的标签页选择对应的播放器
    if (currentTab == 0) { // 本地播放
        if (this->total > 0) {
            position = value * this->total / 100;
            player->setPosition(position);
        }
    } else { // 在线播放
        if (this->onlineTotal > 0) { // 使用在线播放器的总时长
            position = value * this->onlineTotal / 100;
            onlinePlayer->setPosition(position); // 更新在线播放器的位置
        }
    }
}

//点击声音图标
void MusicWindow::on_btn_volume_clicked()
{
    QString mode=ui->btn_volume->property("mode").toString();
    if(mode=="unmute"){//如果当前属性是unmute，点击后属性是mute
        ui->btn_volume->setProperty("mode","mute");
        audioOutput->setVolume(0);
        onlineAudioOutput->setVolume(0);
        ui->volumeSlider->setValue(0);
    }else{//如果当前属性是mute，点击后属性是unmute
        ui->btn_volume->setProperty("mode","unmute");
        audioOutput->setVolume(0.5);// 恢复 50% 音量
        onlineAudioOutput->setVolume(0.5);
        ui->volumeSlider->setValue(50);// 滑动条置 50
    }
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_volume->style()->unpolish(ui->btn_volume);
    ui->btn_volume->style()->polish(ui->btn_volume);
    ui->btn_volume->update();
    mode=ui->btn_volume->property("mode").toString();
    qDebug()<<mode;
}


//通过声音进度条调节声音
void MusicWindow::on_volumeSlider_valueChanged(int value) {
    // 核心：拖动时实时设置音量（0.0-1.0）
    audioOutput->setVolume(value / 100.0);
    onlineAudioOutput->setVolume(value / 100.0);
    // 自动更新进度条显示（无需等到释放）
    ui->volumeSlider->setValue(value); // 保持UI同步（可选，默认已同步）
    if(value==0){
        ui->btn_volume->setProperty("mode","mute");
    }else{
        ui->btn_volume->setProperty("mode","unmute");
    }
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_volume->style()->unpolish(ui->btn_volume);
    ui->btn_volume->style()->polish(ui->btn_volume);
    ui->btn_volume->update();
}

// 解析LRC文件（私有函数）
void MusicWindow::parseLrc(const QString &lrcPath) {
    lrcMap.clear(); // 清空旧歌词
    QFile file(lrcPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开LRC文件:" << lrcPath;
        return;
    }

    // 正则表达式匹配时间戳 [mm:ss.ss]歌词
    QRegularExpression re("\\[(\\d{2}):(\\d{2}(?:\\.\\d{2})?)\\](.*)");
    while (!file.atEnd()) {
        QString line = file.readLine().trimmed();
        QRegularExpressionMatch match = re.match(line);
        if (match.hasMatch()) {
            int min = match.captured(1).toInt();       // 分钟
            int sec = match.captured(2).split('.').first().toInt(); // 秒（忽略毫秒部分）
            qint64 msec = min * 60 * 1000 + sec * 1000; // 转换为毫秒
            QString lyric = match.captured(3).simplified(); // 歌词内容（去除空格）
            lrcMap[msec] = lyric; // 存入映射表
        }
    }
}

// 歌词同步（槽函数）
void MusicWindow::updateLyrics(qint64 currentTime) {
    if (lrcMap.isEmpty()) return; // 无歌词时不处理

    // 查找当前时间对应的歌词行（找到第一个大于currentTime的时间戳，取前一个）
    auto it = lrcMap.upperBound(currentTime);
    int index = std::distance(lrcMap.begin(), it) - 1;
    if (index < 0) index = 0; // 防止越界

    // 只在歌词行变化时更新UI
    if (index == currentLyricIndex) return;
    currentLyricIndex = index;

    // 更新5个Label的歌词（中间行为index，上下各2行）
    for (int i = 0; i < 5; ++i) {
        int targetIndex = index + (i - 2); // i=2时targetIndex=index（中间行）
        QString lyric = (targetIndex >= 0 && targetIndex < lrcMap.size())
                            ? lrcMap.values()[targetIndex] // 取对应歌词
                            : ""; // 超出范围时清空

        // 通过objectName获取Label（需与UI Designer中的名称一致，如lyricLine0-lyricLine4）
        QLabel *label = ui->centralwidget->findChild<QLabel*>(QString("lyricLine%1").arg(i));
        if (label) {
            label->setText(lyric);
            //中间行高亮（假设中间行是lyricLine2）
            if (i == 2) {
                label->setStyleSheet("color: rgb(255, 228, 181);font-size:16pt; font-weight: bold;");
            } else {
                label->setStyleSheet("color: rgb(81, 81, 81);font-size:13pt;");
            }
        }
    }
}





#include "video/videowindow.h"
#include "ui_videowindow.h"
#include <QDebug>
#include <QFileDialog>
#include "common/common.h"
#include <QMessageBox>
#include "video.h"
#include "videodao.h"
#include <QtSql/QSqlError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

VideoWindow::VideoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoWindow)
{
    ui->setupUi(this);

    this->initVideoWin();
}

VideoWindow::~VideoWindow()
{
    delete ui;
}

void VideoWindow::initVideoWin()
{
    // 初始化时间标签
    ui->label_currentTime->setText("00:00");
    ui->label_totalTime->setText("/00:00");

    //给播放按钮设置一个属性mode=(play/pause)
    //播放按钮就应该有一个默认的mode属性值
    ui->btn_play->setProperty("mode","pause");

    //给声音按钮设置一个默认的mode属性值
    ui->btn_volume->setProperty("mode","unmute");

    this->playlist=new QList<QUrl>();           //初始化本地播放列表
    this->player = new QMediaPlayer(this);      //初始化本地播放器
    this->onlinePlaylist=new QList<QUrl>();
    this->onlinePlayer=new QMediaPlayer(this);

    //给视频播放器设置视频输出窗口
    this->videoWidget=new QVideoWidget();
    this->audioOutput = new QAudioOutput(this);  // 创建本地音频输出对象
    this->onlineAudioOutput=new QAudioOutput(this); //创建在线音频输出对象

    //告诉程序，videoWidget要在什么地方
    ui->horizontalLayout->addWidget(videoWidget);
    this->player->setVideoOutput(videoWidget);  // 绑定视频输出
    this->player->setAudioOutput(audioOutput);  // 绑定音频输出（Qt6新增）
    // this->onlinePlayer->setVideoOutput(videoWidget); //初始不绑定,在切换时绑定,实现独有
    this->onlinePlayer->setAudioOutput(onlineAudioOutput);


    // 连接拖动状态信号
    connect(ui->progressSlider, &QSlider::sliderPressed, this, [this]() { isDragging = true; });
    connect(ui->progressSlider, &QSlider::sliderReleased, this, [this]() { isDragging = false; });

    //给QMediaPlayer绑定信号和槽函数，去计算进度条
    connect(this->player,&QMediaPlayer::durationChanged,this,&VideoWindow::durationChanged);
    connect(this->player,&QMediaPlayer::positionChanged,this,&VideoWindow::positionChanged);
    connect(this->onlinePlayer, &QMediaPlayer::durationChanged, this, &VideoWindow::durationChanged);
    connect(this->onlinePlayer,&QMediaPlayer::positionChanged,this,&VideoWindow::positionChanged);

    //给videoWidget安装退出全屏事件过滤器
    this->exitFullScreenFilter=new ExitFullScreenEventFilter();
    this->videoWidget->installEventFilter(this->exitFullScreenFilter);

    //给事件过滤器绑定信号和槽，退出全屏
    connect(this->exitFullScreenFilter,&ExitFullScreenEventFilter::exitFullScreen,this,[this]()->void{
        if (videoWidget->isFullScreen()) {
            videoWidget->setWindowFlags(Qt::SubWindow);
            videoWidget->showNormal();
        } else {
            videoWidget->setWindowFlags(Qt::Window);
            videoWidget->showFullScreen();
        }
    });

    //给videoWidget单击暂停事件过滤器
    this->clickedPauseEventFilter=new ClickedPauseEventFilter();
    this->videoWidget->installEventFilter(this->clickedPauseEventFilter);
    //给事件过滤器绑定信号和槽，退出全屏
    connect(this->clickedPauseEventFilter,&ClickedPauseEventFilter::clickedPause,this,&VideoWindow::on_btn_play_clicked);


    // 查询数据库并缓存Video列表
    VideoDao videoDao;
    videoList = videoDao.queryVideos(); // 获取带Video对象列表
    for (const Video &video : videoList) {
        playlist->append(QUrl::fromLocalFile(video.path())); // 加载视频路径
        ui->list_local_2->addItem(video.name()); // 加载视频名
    }
    if (!videoList.isEmpty()) {
        currentIndex = 0;
        ui->list_local_2->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));
    }

    //初始化在线列表
    this->initOnlineList();
}

void VideoWindow::initOnlineList()
{
    // 向后端服务器发起http请求
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    manager->get(QNetworkRequest(QUrl("http://localhost/video_test.json")));
    connect(manager,&QNetworkAccessManager::finished,this,&VideoWindow::showOnlineList);
}

void VideoWindow::showOnlineList(QNetworkReply *reply)
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
            qDebug()<<"在线视频name:"<<name;
            QString path = obj.value("path").toString();
            ui->list_online_2->addItem(name);
            // 这个地方加入播放列表的时候,不能和本地列表混为一谈
            onlinePlaylist->append(QUrl(path));
        }
        onlineCurrentIndex=0;
        ui->list_online_2->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex));
    }
}

//tab标签切换
void VideoWindow::on_tabWidget_currentChanged(int index)
{
    currentTab=index;
    if(currentTab==0){
        this->onlinePlayer->pause();
        ui->progressSlider->setValue(0);
        onlinePlayer->setVideoOutput(nullptr); // 断开在线播放器的输出
        player->setVideoOutput(videoWidget); // 绑定本地播放器
        // 初始化时间标签
        ui->label_currentTime->setText("00:00");
    }else{
        this->player->pause();
        ui->progressSlider->setValue(0);
        player->setVideoOutput(nullptr); // 断开本地播放器的输出
        onlinePlayer->setVideoOutput(videoWidget); // 绑定在线播放器
        // 初始化时间标签
        ui->label_currentTime->setText("00:00");
    }
    ui->btn_play->setProperty("mode","pause");
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();

    qDebug()<<currentTab;

}

//退出
void VideoWindow::on_btn_quit_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

//保持播放状态
void VideoWindow::keepStatus()
{
    QString mode=ui->btn_play->property("mode").toString();
    int newIndex=ui->list_local_2->currentRow();  //有可能单击选中歌曲索引改变
    int onlineNewIndex=ui->list_online_2->currentRow();
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

// 毫秒转 "分:秒" 格式
QString VideoWindow::msecToTime(qint64 msec) {
    if (msec <= 0) return "00:00"; // 处理无效时间

    int sec = msec / 1000;          // 总秒数
    int min = sec / 60;             // 分钟
    sec %= 60;                      // 剩余秒数

    // 格式化为两位数（不足补0）
    return QString("%1:%2").arg(min, 2, 10, QChar('0'))
        .arg(sec, 2, 10, QChar('0'));
}


//播放当前索引歌曲
void VideoWindow::playAtIndex(int index)
{
    if(currentTab==0){          //本地
        if(index>=0&&index<playlist->size()){
            currentIndex=index;
            player->setSource(playlist->at(currentIndex));
            this->player->play();
        }
    }else{                  //在线
        if(index>=0&&index<onlinePlaylist->size()){
            onlineCurrentIndex=index;
            onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex));
            this->onlinePlayer->play();
        }
    }
}

/**
 * @brief VideoWindow::on_btn_play_clicked
 * 如果当前btn_play的mode的值是pause,点击之后就应该变为play
 * 反之亦然
 */
void VideoWindow::on_btn_play_clicked()
{
    QString mode=ui->btn_play->property("mode").toString();
    int newIndex=ui->list_local_2->currentRow();
    int onlineNewIndex=ui->list_online_2->currentRow();
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
//添加本地视频
void VideoWindow::on_btn_file_clicked()
{
    if(currentTab==1){
        // 弹窗提示
        QMessageBox::warning(
            this,
            "警告",
            QString("请回到本地列表添加视频"),
            QMessageBox::Ok);
        return;
    }
    QStringList files=QFileDialog::getOpenFileNames(
        this,
        "选择视频文件",
        getProjectVideoPath(),
        "Video(*.mp4 *.avi)");
    VideoDao videoDao;
    int addedCount = 0; // 统计新增数量

    for (const QString &filePath : files) {
        QFileInfo fileInfo(filePath);
        QString videoName = fileInfo.fileName();
        Video video(0, videoName, filePath);

        // 通过数据库去重（权威数据源）
        if (videoDao.existsByPath(filePath)) {
            // 弹窗提示已存在（带文件名）
            QMessageBox::warning(
                this,
                "视频已存在",
                QString("《%1》已存在于本地视频库！").arg(videoName),
                QMessageBox::Ok);
            continue; // 跳过已存在的视频
        }

        // 插入数据库（带错误处理）
        if (!videoDao.insertVideo(video)) {
            QMessageBox::critical(
                this,
                "添加失败",
                QString("《%1》插入数据库失败：%2")
                    .arg(videoName)
                    .arg(videoDao.lastError()), // 新增错误信息获取
                QMessageBox::Ok);
            continue;
        }

        // 成功添加到播放列表和UI
        playlist->append(QUrl::fromLocalFile(filePath));
        ui->list_local_2->addItem(videoName);
        addedCount++;
    }

    // 批量添加成功提示
    if (addedCount > 0) {
        QMessageBox::information(
            this,
            "添加完成",
            QString("成功添加 %1 部视频！").arg(addedCount),
            QMessageBox::Ok);
    }
}


//双击本地列表播放视频
void VideoWindow::on_list_local_2_itemDoubleClicked(QListWidgetItem *item)
{
    //获取选中的当前索引，并播放当前歌曲
    currentIndex=ui->list_local_2->currentRow();
    playAtIndex(currentIndex);
    ui->btn_play->setProperty("mode","play");
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();
}
//双击在线列表播放视频
void VideoWindow::on_list_online_2_itemDoubleClicked(QListWidgetItem *item)
{
    //获取选中的当前索引，并播放当前
    onlineCurrentIndex=ui->list_online_2->currentRow();
    playAtIndex(onlineCurrentIndex);
    ui->btn_play->setProperty("mode","play");
    //当属性mode的值发生改变以后，如果想让演示生效，还需要重新刷新样式
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();
}

//前一部视频
void VideoWindow::on_btn_pre_clicked()
{
    if(currentTab==0){
        //本地播放列表非空就播放前一首，如果是第一首，它的前一首就是最后一首
        if(playlist->isEmpty()) return;
        currentIndex=(currentIndex-1+playlist->size())%playlist->size();
        ui->list_local_2->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));      //换源
        qDebug()<<"本地索引"<<currentIndex;
    }else{
        //在线播放列表非空就播放前一首
        if(onlinePlaylist->isEmpty()) return;
        onlineCurrentIndex=(onlineCurrentIndex-1+onlinePlaylist->size())%onlinePlaylist->size();
        ui->list_online_2->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex)); //换源
        qDebug()<<"在线索引"<<onlineCurrentIndex;
    }
    //保持播放状态
    keepStatus();
}


//后一部视频
void VideoWindow::on_btn_next_clicked()
{
    if(currentTab==0){
        //播放列表非空就播放后一首，如果是最后一首，它的后一首就是第一首
        if(playlist->isEmpty()) return;
        currentIndex=(currentIndex+1)%playlist->size();
        ui->list_local_2->setCurrentRow(currentIndex);
        player->setSource(playlist->at(currentIndex));      //换源
        qDebug()<<"本地索引"<<currentIndex;
    }else{
        //播放列表非空就播放后一首，如果是最后一首，它的后一首就是第一首
        if(onlinePlaylist->isEmpty()) return;
        onlineCurrentIndex=(onlineCurrentIndex+1)%onlinePlaylist->size();
        ui->list_online_2->setCurrentRow(onlineCurrentIndex);
        onlinePlayer->setSource(onlinePlaylist->at(onlineCurrentIndex)); //换源
        qDebug()<<"在线索引"<<onlineCurrentIndex;
    }
    //保持播放状态
    keepStatus();
}

//获取的是当前播放视频的总长度
void VideoWindow::durationChanged(qint64 duration)
{
    QObject *src=sender();
    if(src==player){
        this->total=duration;
        if(currentTab==0){// 只有当本地标签页时才更新显示
            ui->label_totalTime->setText("/"+msecToTime(duration));
        }
    }else if(src==onlinePlayer){
        this->onlineTotal = duration;
        if(currentTab==1){// 只有当在线标签页时才更新显示
            ui->label_totalTime->setText("/"+msecToTime(duration)); // 显示总时间（如 04:02）
        }
    }
}

//获取当前视频的播放位置
void VideoWindow::positionChanged(qint64 position)
{
    if (isDragging) return; // 拖动时跳过自动更新
    // 显示当前时间（如 01:49）
    ui->label_currentTime->setText(msecToTime(position));

    // 根据Tab获取对应总时长
    qint64 finalTotal = (currentTab == 0) ? this->total : onlineTotal;

    //在切换的时候，在一段时间内，this->total可能是为0，作分母会报错
    if(finalTotal>0){
        //先乘以100，要不然int相除可能为0
        int value=position*100/finalTotal;
        qDebug()<<"总长度："<<finalTotal<<" 当前："<<position<<"进度"<<value;
        ui->progressSlider->setValue(value);
    }
}

//通过进度滑动条控制播放视频进度
void VideoWindow::on_progressSlider_sliderReleased()
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

//点击音量图标静音
void VideoWindow::on_btn_volume_clicked()
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
//调节音量
void VideoWindow::on_volumeSlider_valueChanged(int value)
{
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

//全屏
void VideoWindow::on_btn_fullScreen_clicked()
{
    //将子窗口设置为顶层窗口
    this->videoWidget->setWindowFlags(Qt::Window);

    //设置全屏
    this->videoWidget->showFullScreen();
}









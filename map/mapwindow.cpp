#include "map/mapwindow.h"  // 包含自身头文件，声明 MapWindow 类
#include "common/common.h"       // 包含通用宏和常量定义
#include "ui_mapwindow.h"  // 包含 UI 设计器生成的类
#include <QNetworkAccessManager>  // 网络请求管理器
#include <QNetworkReply>          // 网络应答对象
#include <QNetworkRequest>        // 网络请求对象
#include <QDateTime>              // 时间日期工具类
#include <QDebug>                 // 调试输出宏
#include <QFile>                  // 文件读写类
#include <QPixmap>                // 图像显示类
#include <QJsonDocument>          // JSON 文档处理类
#include <QJsonObject>            // JSON 对象处理类
#include <QMessageBox>            // 弹出消息框类
#include <QWheelEvent>            // 滚轮事件类
#include "mapdraggingeventfilter.h" //地图拖拽过滤器
#include <cmath>
#include <QMouseEvent>
#include <QTimer>

// 定义地图缩放级别边界
static const int MIN_ZOOM = 3;       // 地图最小缩放级别
static const int MAX_ZOOM_HD = 17;   // 高清图最大缩放级别
static const int DEFAULT_ZOOM = 10;  // 应用启动默认缩放级别

// MapWindow 构造函数：初始化 UI 与网络管理器、安装事件过滤器
MapWindow::MapWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapWindow)                                // 创建 UI 对象
    , manager(new QNetworkAccessManager(this))             // 创建网络管理器，并指定父对象
    , currentMapReply(nullptr)                             // 初始化当前地图请求指针为空
    , zoom(DEFAULT_ZOOM)                                   // 设置当前缩放为默认
    , pendingZoom(DEFAULT_ZOOM)                            // 设置待应用缩放为默认
    , lastOptTime(0)
    , dragging(false)
{
    ui->setupUi(this);                                    // 加载 UI 界面布局

    this->initMapWin();
}

// MapWindow 析构函数：释放 UI 对象
MapWindow::~MapWindow()
{
    delete ui;  // 删除 UI，自动删除其子控件
}

void MapWindow::initMapWin()
{
    ui->label_map->setScaledContents(true);               // 设置 QLabel 根据内容自动缩放

    // 安装自定义滚轮事件过滤器：用于鼠标滚轮控制放大缩小
    this->wheelEventFilter = new WheelEventFilter(this);  // 创建过滤器对象
    ui->label_map->installEventFilter(this->wheelEventFilter); // 将过滤器安装到地图标签
    // 将过滤器信号连接到对应的放大/缩小槽
    connect(this->wheelEventFilter, &WheelEventFilter::mapWheelEvent,
            this, [this](int delta) {
                if (delta > 0) {
                    on_btn_enlarge_clicked();  // 滚轮向上则调用放大逻辑
                } else {
                    on_btn_reduce_clicked();   // 滚轮向下则调用缩小逻辑
                }
            });



    // 为 label_map 启用鼠标事件
    ui->label_map->setMouseTracking(true);
    this->mapDraggingEventFilter=new MapDraggingEventFilter();
    ui->label_map->installEventFilter(this->mapDraggingEventFilter);
    //连接信号与槽，当 dragFilter 对象发出 mapDragging 信号时，执行对应的 lambda 表达式
    connect(this->mapDraggingEventFilter,&MapDraggingEventFilter::mapDragging,
            this,[this](QEvent::Type type, QMouseEvent *me){
                if(type == QEvent::MouseButtonPress && me->button() == Qt::LeftButton){
                    qint64 now = QDateTime::currentMSecsSinceEpoch();
                    // 假设我们把阈值定为 300ms
                    if (now - lastOptTime < 300) {
                        ui->label_map->setText("操作过快,请重新拖慢一点...\n重拖一次刷新地图");            // 显示加载提示
                        ui->label_map->setStyleSheet("color:white; font-size: 45px; font-weight: bold;");
                        return;
                    }
                    lastOptTime=now;  // 更新拖拽时间戳
                    // 当检测到鼠标左键按下时，将 dragging 标志设置为 true，表示开始拖拽操作
                    dragging = true;
                    // 记录当前鼠标的位置，作为后续计算鼠标移动偏移量的起始点
                    lastMousePos = me->pos();
                }else if(type == QEvent::MouseMove && dragging){
                    //如果想拖的时候也刷新,可以将鼠标释放里的东西放这里,但是一直刷新费访问次数
                }else if(type == QEvent::MouseButtonRelease && me->button() == Qt::LeftButton) {
                    qint64 now = QDateTime::currentMSecsSinceEpoch();
                    // 假设我们把阈值定为 300ms
                    if (now - lastOptTime < 300) {
                        ui->label_map->setText("操作过快,请重新拖慢一点...\n重拖一次刷新地图");            // 显示加载提示
                        ui->label_map->setStyleSheet("color:white; font-size: 45px; font-weight: bold;");
                        return;
                    }
                    lastOptTime=now;  // 更新拖拽时间戳
                    // 计算当前鼠标位置与上一次记录位置的差值，得到鼠标在屏幕上的偏移量
                    QPoint delta =me->pos()-lastMousePos;
                    lastMousePos=me->pos();

                    // 1. 像素转经度（大致估算）
                    //    地球周长大约 40075 km，经度 360°，
                    //    tileSize = 256 * 2^zoom 像素 对应 360°
                    double pixelPerLonDeg=256.0*std::pow(2.0,zoom)/360.0;
                    double pixelPerLatDeg=pixelPerLonDeg;// 近似：纬度同等像素度数

                    // 2. 根据鼠标在 x 轴上的偏移量计算经度的变化量
                    //    根据鼠标在 y 轴上的偏移量计算纬度的变化量
                    double dLon=-delta.x()/pixelPerLonDeg;
                    double dLat=delta.y()/pixelPerLatDeg;

                    // 3. 更新中心经纬度
                    // 将当前的经度和纬度字符串转换为双精度浮点数，并检查转换是否成功
                    bool ok1,ok2;
                    double lon0=lng.toDouble(&ok1);
                    double lat0=lat.toDouble(&ok2);
                    if(ok1&&ok2){
                        // 根据计算得到的经度和纬度变化量，更新当前的经度和纬度
                        lng=QString::number(lon0+dLon,'f',6);
                        lat=QString::number(lat0+dLat,'f',6);
                        initMap(true);// 调用 initMap 函数，重新加载地图并显示标记
                    }
                    dragging = false;
                }
            });
    this->getIp();  // 向 ipinfo.io 发起请求以获取公网 IP
}

// 通用网络应答处理槽
void MapWindow::handleNetworkReply()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender()); // 获取发出信号的 reply 对象
    if (!reply) return;                                          // 如果为空则直接返回

    QString operation = reply->property("operation").toString(); // 读取标记操作类型
    int replyZoom = reply->property("zoom").toInt();            // 读取标记的缩放级别

    // 输出调试信息：操作类型、缩放级别、错误码、HTTP 状态码
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "[Reply] operation=" << operation
             << ", zoom=" << replyZoom
             << ", error=" << reply->error()
             << ", HTTP status=" << httpStatus;

    if (operation == "ip") {
        readIp(reply);       // 处理 IP 返回
    } else if (operation == "lnglat") {
        readLngLat(reply);   // 处理经纬度返回
    } else if (operation == "map") {
        // 丢弃旧的并发响应：只有与 pendingZoom 匹配时才处理
        if (replyZoom != pendingZoom) {
            qDebug() << "丢弃旧响应: pendingZoom=" << pendingZoom << ", replyZoom=" << replyZoom;
            reply->deleteLater();
            return;
        }
        // 读取地图图片二进制
        QByteArray data = reply->readAll();
        // 调试：将图片写入本地文件
        // QFile f("debug_map.png");
        // if (f.open(QIODevice::WriteOnly)) {
        //     f.write(data);
        //     f.close();
        //     qDebug() << "已保存 debug_map.png, 大小=" << data.size();
        // }
        // 将二进制加载到 QPixmap 并显示
        QPixmap pix;
        if (pix.loadFromData(data)) {
            ui->label_map->setPixmap(pix.scaled(
                ui->label_map->size(),        // 目标尺寸：取 label_map 的当前大小
                Qt::KeepAspectRatio,          // 保持原图宽高比，避免拉伸变形
                Qt::SmoothTransformation     // 使用平滑转换（双线性滤波），缩放后画面更平滑细腻
                ));
        } else {
            // 加载失败则提示文字
            qDebug() << "地图渲染失败: 数据无法解析为图像";
            ui->label_map->setText("地图加载失败");
            ui->label_map->setStyleSheet("color:white; font-size: 45px; font-weight: bold;");
        }
        currentMapReply = nullptr;      // 重置当前请求指针
        reply->deleteLater();           // 释放 reply 对象
    }
}

// 发起获取公网 IP 请求
void MapWindow::getIp()
{
    QUrl url("https://ipinfo.io/ip");             // IP 服务地址
    QNetworkReply *reply = manager->get(QNetworkRequest(url)); // GET 请求
    reply->setProperty("operation", "ip");      // 标记为 IP 操作
    connect(reply, &QNetworkReply::finished, this, &MapWindow::handleNetworkReply); // 连接完成信号
}

// 处理 IP 请求的返回
void MapWindow::readIp(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();              // 读取 IP 字符串
    ip = QString(data).trimmed();                    // 转换为 QString 并去除多余空白
    qDebug() << "获取 IP:" << ip;                 // 输出 IP
    reply->deleteLater();                            // 删除 reply 对象
    getLngLat();                                     // 发起下一步：获取经纬度
}

// 发起获取经纬度请求
void MapWindow::getLngLat()
{
    QString urlStr = QString(BAIDU_MAP_IP_URL).arg(ip).arg(BAIDU_MAP_AK); // 拼接百度 IP 定位 URL
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(urlStr)));    // GET 请求
    reply->setProperty("operation", "lnglat"); // 标记操作类型
    connect(reply, &QNetworkReply::finished, this, &MapWindow::handleNetworkReply);
}

// 处理经纬度请求的返回
void MapWindow::readLngLat(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();              // 读取 JSON 数据
    qDebug() << "获取经纬度返回:" << QString(data); // 输出原始 JSON
    reply->deleteLater();                            // 删除 reply 对象

    QJsonDocument doc = QJsonDocument::fromJson(data); // 解析 JSON
    if (!doc.isObject()) {                            // 校验格式
        QMessageBox::warning(this, "错误", "经纬度解析失败");
        return;
    }
    QJsonObject obj = doc.object();                   // 获取根对象
    QJsonObject content = obj.value("content").toObject(); // 提取 content 部分
    QJsonObject point = content.value("point").toObject(); // 提取 point 对象
    lng = point.value("x").toString();              // 解析经度
    lat = point.value("y").toString();              // 解析纬度
    qDebug() << "解析到坐标:" << lng << lat;       // 输出坐标
    initMap(true);                                   // 初始化地图并加标记
}

// 发起静态地图请求并显示
void MapWindow::initMap(bool withMarker)
{
    //ui->label_map->clear();                          // 清空旧图片/文字
   // ui->label_map->setText("加载中...");            // 显示加载提示
   // ui->label_map->setStyleSheet("color:white; font-size: 45px; font-weight: bold;");

    pendingZoom = zoom;                              // 记录当前缩放级别
    if (currentMapReply && currentMapReply->isRunning()) { // 若有未完成请求
        currentMapReply->abort();                    // 取消旧请求
        currentMapReply->deleteLater();              // 删除旧 reply
    }

    QString url = QString(BAIDU_MAP_URL)
                      .arg(BAIDU_MAP_AK)            // API Key
                      .arg(lng).arg(lat)            // 中心经纬度
                      .arg(pendingZoom);            // 缩放级别
    if (withMarker && !lng.isEmpty() && !lat.isEmpty()) {
        url += QString("&markers=%1,%2&markerStyles=l,,red").arg(lng).arg(lat); // 添加红色大号标记
    }
    qDebug() << "请求地图 zoom=" << pendingZoom << url; // 输出请求 URL

    currentMapReply = manager->get(QNetworkRequest(QUrl(url))); // 发送请求
    currentMapReply->setProperty("operation", "map");   // 标记为 map 操作
    currentMapReply->setProperty("zoom", pendingZoom);   // 附加 zoom 属性
    connect(currentMapReply, &QNetworkReply::finished, this, &MapWindow::handleNetworkReply);
}

// 退出按钮点击槽
void MapWindow::on_btn_quit_clicked()
{
    this->hide();                                   // 隐藏当前窗口
    if (parentWidget()) parentWidget()->show();     // 恢复显示父窗口
}

// 放大按钮点击槽
void MapWindow::on_btn_enlarge_clicked()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch(); // 获取当前时间戳
    if (now - lastOptTime < 300) return;             // 防抖：300ms 内忽略
    lastOptTime = now;                               // 更新时间戳
    if (zoom >= MAX_ZOOM_HD) {                        // 达到最大缩放则提示
        QMessageBox::warning(this, "警告", QString("已经最大化，不能继续放大 (最大 %1)").arg(MAX_ZOOM_HD));
        return;
    }
    zoom++;                                           // 增加缩放级别
    initMap(true);                                    // 刷新地图
}

// 缩小按钮点击槽
void MapWindow::on_btn_reduce_clicked()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch(); // 获取当前时间戳
    if (now - lastOptTime < 300) return;             // 防抖：300ms 内忽略
    lastOptTime = now;                               // 更新时间戳
    if (zoom <= MIN_ZOOM) {                           // 达到最小缩放则提示
        QMessageBox::warning(this, "警告", QString("已经最小化，不能继续缩小 (最小 %1)").arg(MIN_ZOOM));
        return;
    }
    zoom--;                                           // 减少缩放级别
    initMap(true);                                    // 刷新地图
}

// 定位按钮点击槽：重置缩放并刷新
void MapWindow::on_btn_locate_clicked()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch(); // 获取当前时间戳
    if (now - lastOptTime < 600) return;             // 防抖：300ms 内忽略
    lastOptTime = now;                               // 更新时间戳
    zoom = DEFAULT_ZOOM;                              // 重置为默认缩放级别
    this->getIp();                                  // 刷新地图并标记

}

// 路线规划按钮点击槽（待实现）
void MapWindow::on_btn_getRoute_clicked()
{
    // TODO: 实现路径规划逻辑
}

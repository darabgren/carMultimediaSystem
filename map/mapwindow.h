#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>    //引入网络请求回复类
#include <QDateTime>        //引入日期时间类
#include "map/wheeleventfilter.h"   //引入滚轮事件过滤器
#include "map/mapdraggingeventfilter.h" //引入地图拖拽事件过滤器

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr);
    ~MapWindow();
    void initMapWin();

    void getIp();   // 发起获取公网 IP 请求
    void getLngLat(); // 发起获取经纬度请求
    void readIp(QNetworkReply *reply);// 处理 IP 响应
    void readLngLat(QNetworkReply *reply); // 发起获取经纬度请求
    void initMap(bool withMarker = false);// 发起地图静态图请求，带可选标记

private slots:
    void on_btn_quit_clicked();

    void on_btn_enlarge_clicked();

    void on_btn_reduce_clicked();

    void on_btn_locate_clicked();

    void on_btn_getRoute_clicked();

    void handleNetworkReply();  // 通用网络应答处理槽


private:
    Ui::MapWindow *ui;
    QString ip;     // 存储获取的公网 IP
    QString lng;    //经度
    QString lat;    //纬度
    int zoom;  //放缩等级
    QNetworkAccessManager *manager; // 唯一网络管理器（类成员）
    QNetworkReply *currentMapReply; // 记录当前地图请求（用于取消）
    int pendingZoom; // 记录待处理的缩放级别（防并发丢失）
    WheelEventFilter *wheelEventFilter; //滚轮事件过滤器(地图放大缩小)
    bool dragging;   //是否正在拖拽
    QPoint lastMousePos; //上次鼠标拖拽
    MapDraggingEventFilter *mapDraggingEventFilter;
    qint64 lastOptTime;  // 上次操作的时间戳
};

#endif // MAPWINDOW_H

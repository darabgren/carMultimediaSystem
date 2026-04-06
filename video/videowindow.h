#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMediaPlayer>
#include <QListWidgetItem>
#include <QVideoWidget>
#include <QAudioOutput>
#include "video.h"
#include "videodao.h"
#include "video/exitfullscreeneventfilter.h"
#include "common/clickedpauseeventfilter.h"
#include <QNetworkReply>

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();
    void initVideoWin();

    void playAtIndex(int index);
    void keepStatus();
    QString msecToTime(qint64 msec); // 毫秒转 "分:秒" 格式
    void initOnlineList();  //初始化在线列表

private slots:
    void on_btn_quit_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_btn_volume_clicked();

    void on_btn_file_clicked();

    void on_list_local_2_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_pre_clicked();

    void on_btn_next_clicked();

    void on_btn_play_clicked();

    void on_progressSlider_sliderReleased();

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void on_btn_fullScreen_clicked();

    void showOnlineList(QNetworkReply *reply);

    void on_tabWidget_currentChanged(int index);

    void on_list_online_2_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::VideoWindow *ui;
    QVideoWidget *videoWidget;

    QMediaPlayer *player;   //本地播放器
    QList<QUrl> *playlist;

    QMediaPlayer *onlinePlayer; //在线播放器
    QList<QUrl> *onlinePlaylist;

    QAudioOutput *audioOutput;  //本地音频输出
    QAudioOutput *onlineAudioOutput;

    int currentTab=0; //0=本地,1=在线

    int currentIndex=-1;        //本地当前索引
    int onlineCurrentIndex=-1;  //在线当前索引

    int total;  //本地视频总时长
    int onlineTotal;    //在线视频总时长

    bool isDragging = false; // 拖动状态标记
    QList<Video> videoList; // 缓存从数据库查询的视频列表

    ExitFullScreenEventFilter *exitFullScreenFilter;
    ClickedPauseEventFilter *clickedPauseEventFilter;

};

#endif // VIDEOWINDOW_H

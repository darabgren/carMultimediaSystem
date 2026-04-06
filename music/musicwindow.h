#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QListWidgetItem>
#include <QList>
#include <QUrl>
#include <QAudioOutput>
#include "lyriccontainer.h"
#include "music.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicWindow(QWidget *parent = nullptr);
    ~MusicWindow();
    void initMusicWin();

    void playAtIndex(int index);
    void keepStatus();
    QString msecToTime(qint64 msec); // 毫秒转 "分:秒" 格式
    void initOnlineList();  //初始化在线列表
    void tempDownloadOnlineLrc();//临时下载在线歌词

private slots:
    void on_btn_play_clicked();

    void on_btn_quit_clicked();

    void on_btn_file_clicked();

    void on_list_local_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_next_clicked();

    void on_btn_pre_clicked();

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void on_progressSlider_sliderReleased();

    void on_btn_volume_clicked();

    void on_volumeSlider_valueChanged(int value);

    void updateLyrics(qint64 currentTime); // 歌词同步槽函数

    void showOnlineList(QNetworkReply *reply);


    void on_list_online_itemDoubleClicked(QListWidgetItem *item);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MusicWindow *ui;
    QMediaPlayer *player;       //本地播放器
    QList<QUrl> *playlist;

    QMediaPlayer *onlinePlayer; //在线播放器
    QList<QUrl> *onlinePlaylist;
    QList<QUrl> *onlineLrcList;              // 在线歌词 URL 列表（与 onlinePlaylist 对应）

    int currentTab=0; //0=本地,1=在线

    QAudioOutput *audioOutput;  //本地音频输出
    QAudioOutput *onlineAudioOutput; //在线音频输出
    int currentIndex=-1;            //本地当前索引
    int onlineCurrentIndex=-1;      //在线当前索引

    int total;  //本地音乐总时长
    int onlineTotal;    //在线音乐总时长
    bool isDragging = false; // 拖动状态标记

    //歌词相关成员
     QMap<qint64, QString> lrcMap;       // 时间戳（毫秒）→ 歌词内容
     int currentLyricIndex = 2;          // 中间行Label的索引（0-4，2为中间）
     void parseLrc(const QString &lrcPath); // 解析LRC文件

     QList<Music> musicList; // 缓存从数据库查询的音乐列表（包含lrc_path）
};

#endif // MUSICWINDOW_H

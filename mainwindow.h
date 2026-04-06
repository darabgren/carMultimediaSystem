#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "common/labelclickeventfilter.h"
#include "weather/weatherwindow.h"
#include "music/musicwindow.h"
#include "video/videowindow.h"
#include "map/mapwindow.h"
#include "photo/photowindow.h"
#include "gobang/gobangwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showDateTime();
    void goPage(QObject *watched);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    LabelClickEventFilter *eventFilter;
    WeatherWindow *weatherWin;
    MusicWindow *musicWin;
    VideoWindow *videoWin;
    MapWindow *mapWin;
    PhotoWindow *photoWin;
    GobangWindow *gobangWin;
};
#endif // MAINWINDOW_H

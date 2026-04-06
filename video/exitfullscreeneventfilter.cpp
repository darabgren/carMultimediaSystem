#include "exitfullscreeneventfilter.h"

#include <QKeyEvent>
#include <QDebug>

ExitFullScreenEventFilter::ExitFullScreenEventFilter(QObject *parent)
    : QObject{parent}
{}

/**
 * @brief ExitFullScreenEventFilter::eventFilter
 * @param watched
 * @param event 捕获Esc按键按下和鼠标双击时间，如果捕获到，就要退出全屏
 * @return
 */
bool ExitFullScreenEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    //因为退出全屏的对象在VideoWindow对象中，因此我们不能在此直接操作，而要发送信号通知VideoWindow
    QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
    if(event->type()==QEvent::MouseButtonDblClick||keyEvent->key()==Qt::Key_Escape){
        qDebug()<<event->type();
        qDebug()<<keyEvent->key();

        //退出全屏
        emit exitFullScreen();
    }
    return QObject::eventFilter(watched,event);
}


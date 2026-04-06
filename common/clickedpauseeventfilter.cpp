#include "clickedpauseeventfilter.h"
#include <QKeyEvent>

ClickedPauseEventFilter::ClickedPauseEventFilter(QObject *parent)
    : QObject{parent}
{}

bool ClickedPauseEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
    if(event->type()==QEvent::MouseButtonRelease||keyEvent->key()==Qt::Key_Space){
        qDebug()<<event->type();
        qDebug()<<keyEvent->key();

        //退出全屏
        emit clickedPause();
    }
    return QObject::eventFilter(watched,event);
}

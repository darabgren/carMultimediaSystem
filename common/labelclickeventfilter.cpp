#include "labelclickeventfilter.h"
#include <QDebug>

LabelClickEventFilter::LabelClickEventFilter(QObject *parent)
    : QObject{parent}
{}

/**
 * @brief LabelClickEventFilter::eventFilter
 * @param watched   目标对象
 * @param event 事件对象
 * @return
 */
bool LabelClickEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    //捕获鼠标点击或双击事件
    if(event->type()==QEvent::MouseButtonPress||
        event->type()==QEvent::MouseButtonDblClick){
        qDebug() << "主界面的"<< watched->objectName() <<"label被点击了.........";
        //发送去跳转窗口的信号,并把目标对象传过去
        emit goOtherWindow(watched);
    }
    return QObject::eventFilter(watched,event);
}


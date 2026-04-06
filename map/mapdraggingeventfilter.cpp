#include "mapdraggingeventfilter.h"
#include <QEvent>

MapDraggingEventFilter::MapDraggingEventFilter(QObject *parent)
    : QObject{parent}
{}

bool MapDraggingEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    // 只捕获鼠标按下、移动、释放
    if (event->type() == QEvent::MouseButtonPress ||
        event->type() == QEvent::MouseMove ||
        event->type() == QEvent::MouseButtonRelease)
    {
        auto *me = static_cast<QMouseEvent*>(event);
        emit mapDragging(event->type(), me);
        return true;  // 事件已处理，不再向下分发
    }
    return false;
    // 其它事件交给基类处理
    //return QObject::eventFilter(watched, event);
}

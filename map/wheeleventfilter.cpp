#include "wheeleventfilter.h"
#include <QWheelEvent>

WheelEventFilter::WheelEventFilter(QObject *parent)
    : QObject{parent}
{}
bool WheelEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Wheel) {
        auto *wheel = static_cast<QWheelEvent*>(event);
        emit mapWheelEvent(wheel->angleDelta().y());
    }
    return QObject::eventFilter(watched,event);
}

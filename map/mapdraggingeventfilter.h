#ifndef MAPDRAGGINGEVENTFILTER_H
#define MAPDRAGGINGEVENTFILTER_H

#include <QObject>
#include <QMouseEvent>
class MapDraggingEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit MapDraggingEventFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event) override;
signals:
    // 发出拖拽事件：传递事件类型和对应的 QMouseEvent*
    void mapDragging(QEvent::Type eventType, QMouseEvent *me);
};

#endif // MAPDRAGGINGEVENTFILTER_H

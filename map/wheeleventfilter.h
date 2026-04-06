#ifndef WHEELEVENTFILTER_H
#define WHEELEVENTFILTER_H

#include <QObject>
#include <QWheelEvent>

class WheelEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit WheelEventFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void mapWheelEvent(int delta);
};

#endif // WHEELEVENTFILTER_H

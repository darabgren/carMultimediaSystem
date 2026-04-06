#ifndef LABELCLICKEVENTFILTER_H
#define LABELCLICKEVENTFILTER_H

#include <QObject>
#include <QEvent>

class LabelClickEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit LabelClickEventFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);
signals:
    void goOtherWindow(QObject *watched);
};

#endif // LABELCLICKEVENTFILTER_H

#ifndef CLICKEDPAUSEEVENTFILTER_H
#define CLICKEDPAUSEEVENTFILTER_H

#include <QObject>
#include <QEvent>

class ClickedPauseEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit ClickedPauseEventFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void clickedPause();
};

#endif // CLICKEDPAUSEEVENTFILTER_H

#ifndef LYRICCONTAINER_H
#define LYRICCONTAINER_H

#include <QFrame>
#include <QObject>

class LyricContainer : public QFrame {
    Q_OBJECT
public:
    // 确保有这个构造函数
    explicit LyricContainer(QWidget *parent = nullptr) : QFrame(parent) {}
};

#endif // LYRICCONTAINER_H

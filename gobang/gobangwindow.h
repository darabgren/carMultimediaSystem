#ifndef GOBANGWINDOW_H
#define GOBANGWINDOW_H

#include <QMainWindow>

#include "Stone.h"
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QEvent>


namespace Ui {
class GobangWindow;
}

class GobangWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GobangWindow(QWidget *parent = nullptr);
    ~GobangWindow();

    void paintEvent(QPaintEvent *event);  //处理窗口绘制事件

    void drawChessboard();  //绘制棋盘

    void drawStoneAtPoint(QPainter &painter, const QPoint &position); //在指定位置绘制单个棋子

    void drawStones();  //绘制所有已经放置的棋子

    void mousePressEvent(QMouseEvent *event);   //处理鼠标点击事件

    bool checkWin(const Stone& newStone);

private slots:
    void on_btn_quit_clicked();

    void on_btn_take_back_clicked();

    void on_btn_give_up_clicked();

    void on_btn_restart_clicked();

    void on_btn_request_draw_clicked();

private:
    Ui::GobangWindow *ui;

    QVector<Stone> stones;  //存储所有棋子的容器
    bool isBlackTurn=true;   //标记当前轮到的玩家(true为黑棋),开局黑棋先手
    bool isGameOver=false;    //标记游戏是否结束
};

#endif // GOBANGWINDOW_H

#include "gobangwindow.h"
#include "ui_gobangwindow.h"

#include "common/common.h"
#include <QMessageBox>
#include <QMouseEvent>

GobangWindow::GobangWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GobangWindow)
{
    ui->setupUi(this);
}

GobangWindow::~GobangWindow()
{
    delete ui;
}

void GobangWindow::paintEvent(QPaintEvent *event)
{
    drawChessboard();   //绘制棋盘
    drawStones();   //绘制已放置的棋子
}

void GobangWindow::drawChessboard()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);// 关闭抗锯齿（针对像素级精确绘制，线条更锐利但无平滑效果）

    // 填充背景
    QRect boardRect(GRID_WIDTH/2, GRID_HEIGHT/2,
                    (CHESSBOARD_COLS-1)*GRID_WIDTH,
                    (CHESSBOARD_ROWS-1)*GRID_HEIGHT);
    painter.fillRect(boardRect, QColor("#E7C273"));  // 背景填充

    // 粗边框
    QPen borderPen(Qt::black);
    borderPen.setWidth(3);
    painter.setPen(borderPen);
    painter.drawRect(boardRect);

    // 细线网格：只画内部 13 条
    QPen linePen(Qt::black);
    linePen.setWidth(1);
    painter.setPen(linePen);
    int x0 = GRID_WIDTH/2, y0 = GRID_HEIGHT/2;
    // 垂直内部线
    for (int i = 1; i < CHESSBOARD_COLS-1; ++i) {
        int x = x0 + i * GRID_WIDTH;
        painter.drawLine(x, y0, x, y0 + (CHESSBOARD_ROWS-1)*GRID_HEIGHT);
    }
    // 水平内部线
    for (int j = 1; j < CHESSBOARD_ROWS-1; ++j) {
        int y = y0 + j * GRID_HEIGHT;
        painter.drawLine(x0, y, x0 + (CHESSBOARD_COLS-1)*GRID_WIDTH, y);
    }

    // 星位标记
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);
    const QVector<QPoint> stars = {{3,3},{3,11},{11,3},{11,11},{7,7}};
    int r = GRID_WIDTH/8;  // 半径
    for (auto &pt : stars) {
        int cx = x0 + pt.x()*GRID_WIDTH;
        int cy = y0 + pt.y()*GRID_HEIGHT;
        painter.drawEllipse(QPoint(cx, cy), r, r);
    }
}

void GobangWindow::drawStoneAtPoint(QPainter &painter, const QPoint &position)
{
    //计算棋子中心位置
    QPoint positionCenter((position.x()+0.5)*GRID_HEIGHT,(position.y()+0.5)*GRID_HEIGHT);
    //绘制圆形表示棋子
    painter.drawEllipse(positionCenter,GRID_WIDTH/2,GRID_HEIGHT/2);

    update();
}


void GobangWindow::drawStones()
{
    QPainter painter(this);     //创建绘画对象
    //painter.setPen(QPen(QColor(Qt::transparent)));  //设置无边框

    //遍历所有已经放置的棋子
    for(Stone stone:stones){
        if(stone.isBlackStone){     //根据棋子颜色设置画笔颜色
            painter.setBrush(Qt::black);    //黑棋
        }else{
            painter.setBrush(Qt::white);    //白棋
        }
        drawStoneAtPoint(painter,stone.position);
    }

    update();
}


//鼠标点击事件处理
void GobangWindow::mousePressEvent(QMouseEvent *event)
{
    if(!this->isGameOver){
        //计算鼠标点击的棋盘位置(将鼠标坐标转为棋盘行列坐标)
        QPoint position;
        position.setX((event->pos().x())/GRID_WIDTH);
        position.setY((event->pos().y())/GRID_HEIGHT);

        //检查该位置是否已经有棋子
        for(Stone stone:stones){
            if(stone.position==position){
                return; //已经有棋子,不做处理
            }
        }

        //检查是否在棋盘外
        //棋盘有效的列索引是 0～CHESSBOARD_COLS-1
        if (position.x() < 0 || position.x() >= CHESSBOARD_COLS ||
            position.y() < 0 || position.y() >= CHESSBOARD_ROWS) {
            return;
        }


        Stone newStone(position,isBlackTurn);     //“玩家轮次” 与 “棋子颜色” 对应
        stones.append(newStone);   //将新棋子添加到棋子容器中

        if(checkWin(newStone)){
            QString winner=isBlackTurn? "黑方":"白方";
            QMessageBox::information(this,"游戏结束",winner+"获胜!",QMessageBox::Yes);

            return;
        }
        isBlackTurn=!isBlackTurn;   //切换玩家
        if(isBlackTurn==true){
            ui->label_player->setText("Black");
            ui->label_player->setStyleSheet("color:black");
        }else{
            ui->label_player->setText("White");
            ui->label_player->setStyleSheet("color:gray");
        }
    }else{
         QMessageBox::information(this, "提示", "游戏已经结束,不能落子!");
    }

}


bool GobangWindow::checkWin(const Stone &newStone)
{
    // 定义8个方向：左、左上、上、右上、右、右下、下、左下
    QVector<QPoint> directions={
        QPoint(-1,0),QPoint(-1,-1),QPoint(0,-1),QPoint(1,-1),
        QPoint(1,0),QPoint(1,1),QPoint(0,1),QPoint(-1,1)
    };

    //检查每个方向
    for(int i=0;i<4;i++){//只需检查4对方向(每对方向相加)
        QPoint dir1=directions[i];
        QPoint dir2=directions[i+4];    //相反方向

        //计算第一个方向上的相连棋子数(不包括当前棋子)
        Stone tempStone=newStone;
        int count1=0;
        tempStone.position+=dir1;   //沿指定方向移动一个格子
        while(stones.contains(tempStone)){
            count1++;   //计数加1
            tempStone.position+=dir1;   //继续沿该方向移动
        }
        //计算第二个方向上的相连棋子数(不包括当前棋子)
        tempStone=newStone;
        int count2=0;
        tempStone.position+=dir2;
        while(stones.contains(tempStone)){
            count1++;   //计数加1
            tempStone.position+=dir2;   //继续沿该方向移动
        }

        //如果两个方向连棋子数之和大于等于4(加上当前棋子共5个),则获胜
        if(count1+count2>=4){
            this->isGameOver=true;
            return true;
        }
    }
    return false;   //没有获胜
}

//退出
void GobangWindow::on_btn_quit_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

//悔棋
void GobangWindow::on_btn_take_back_clicked()
{
    if(!this->isGameOver){   //如果游戏没有结束
        if(!stones.isEmpty()){  //如果棋盘上还有棋子
            // 弹出确认对话框(是否同意对方悔棋)
            QString takeBackRequest=QString("%1请求悔棋,是否同意?").arg(isBlackTurn? "黑方":"白方");
            int reply = QMessageBox::question(
                this,                  // 父窗口（当前窗口）
                "悔棋请求",            // 对话框标题
                takeBackRequest,  // 提示信息
                QMessageBox::Yes | QMessageBox::No,  // 按钮：同意/拒绝
                QMessageBox::Yes        // 默认选择（同意）
                );
            if(reply==QMessageBox::Yes){
                //对方同意悔棋,执行悔棋逻辑
                if(!stones.isEmpty()){
                    if(stones.size()>=2){
                        stones.removeLast();
                        stones.removeLast();
                    }else{
                        stones.removeLast();
                        isBlackTurn=!isBlackTurn;   //切换玩家
                        if(isBlackTurn==true){
                            ui->label_player->setText("Black");
                            ui->label_player->setStyleSheet("color:black");
                        }else{
                            ui->label_player->setText("White");
                            ui->label_player->setStyleSheet("color:gray");
                        }

                    }
                    update();
                }
            }else{
                // 对方拒绝悔棋，提示信息
                QMessageBox::information(this, "提示", "对方拒绝了悔棋请求");
            }
        }else{  //棋盘上没有棋子
            QMessageBox::information(this, "提示", "悔无可悔,无须再悔!");
        }
    }else{  //游戏结束
        QMessageBox::information(this, "提示", "游戏已经结束,现在悔棋好像有亿点晚了!");
    }

}

//求和
void GobangWindow::on_btn_request_draw_clicked()
{
    if(!this->isGameOver){   //如果游戏没有结束
        // 弹出确认对话框(是否同意对方的和棋请求)
        QString drawRequest=QString("%1请求和棋,是否同意?").arg(isBlackTurn? "黑方":"白方");
        int reply = QMessageBox::question(
            this,                  // 父窗口（当前窗口）
            "和棋请求",            // 对话框标题
            drawRequest,  // 提示信息
            QMessageBox::Yes | QMessageBox::No,  // 按钮：同意/拒绝
            QMessageBox::Yes        // 默认选择（同意）
            );
        if(reply==QMessageBox::Yes){
            QMessageBox::information(this, "游戏结束", "达成平局!");
            this->isGameOver=true;
        }
    }else{
        QMessageBox::information(this, "提示", "游戏已经结束,现在和棋好像有亿点晚了!");
    }
}

//认输
void GobangWindow::on_btn_give_up_clicked()
{
    if(!this->isGameOver){
        int reply = QMessageBox::question(
            this,                  // 父窗口（当前窗口）
            "认输",            // 对话框标题
            "你确认认输吗?",  // 提示信息
            QMessageBox::Yes | QMessageBox::No,  // 按钮：同意/拒绝
            QMessageBox::Yes        // 默认选择（同意）
            );
        if(reply==QMessageBox::Yes){
            QString loser=isBlackTurn? "黑方":"白方"; //认输的就是当前玩家
            QString winner=!isBlackTurn? "黑方":"白方"; //当前玩家取反就是赢家
            QMessageBox::information(this,"游戏结束",loser+"认输,"+winner+"获胜!",QMessageBox::Yes);
            this->isGameOver=true;
        }else{
            return;
        }
    }else{
        QMessageBox::information(this, "提示", "游戏已经结束,不能重复认输");
    }

}

//重开
void GobangWindow::on_btn_restart_clicked()
{
    // 弹出对话框提问是否重新开局
    int reply = QMessageBox::question(
        this,                  // 父窗口（当前窗口）
        "重开",            // 对话框标题
        "请问是否重新开始?",  // 提示信息
        QMessageBox::Yes | QMessageBox::No,  // 按钮：同意/拒绝
        QMessageBox::Yes        // 默认选择（拒绝）
        );
    if(reply==QMessageBox::Yes){    //同意重开
        stones.clear();         //棋盘清空
        update();

        this->isBlackTurn=true;     //黑棋先落子
        ui->label_player->setText("Black");
        ui->label_player->setStyleSheet("color:black");

        this->isGameOver=false;     //游戏结束标志重置
    }else{
        return;
    }

}




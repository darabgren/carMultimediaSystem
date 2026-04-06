#ifndef STONE_H
#define STONE_H
#include <QPoint>

class Stone
{
public:
    Stone();
    Stone(QPoint position,bool isBlackStone);   //带参构造,初始化棋子位置和颜色
    ~Stone();
    // 重载==运算符，用于比较两个棋子是否相同（位置和颜色都相同）
    bool operator==(const Stone &stone) const{
        return((position==stone.position)&&(isBlackStone==stone.isBlackStone));
    }

public:
    QPoint position;    // 棋子在棋盘上的位置（行列坐标）
    bool isBlackStone;  // 棋子颜色（true为黑棋，false为白棋）

};

#endif // STONE_H

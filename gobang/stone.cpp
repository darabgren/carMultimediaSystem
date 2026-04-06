#include "stone.h"

Stone::Stone() {}

Stone::Stone(QPoint position, bool isBlackStone){
    this->position=position;
    this->isBlackStone=isBlackStone;
}

Stone::~Stone(){

}

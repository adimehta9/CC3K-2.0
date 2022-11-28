#include "player.h"
#include "display.h"
#include "graphics.h"
#include "boardObjects.h"
#include <memory>


#ifndef BOARD__H
#define BOARD__H


class Board{
    shared_ptr<Player> one;
    shared_ptr<Player> two;
    shared_ptr<Display> dis;
    Graphics graph;
    bool graphics;
    
    public:
    
    Board(shared_ptr<Player> one, shared_ptr<Player> two, bool graphics);
    void showBoard(bool one_turn);
    void move(char l, string dir, bool one_turn);
    


};





#endif
#ifndef BOARDOBJECTS__H
#define BOARDOBJECTS__H
#include <map> 
#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class BoardObjects{
    char c;
    int x;
    int y;
    int owner;

    public:
    BoardObjects(char c, int x, int y, int owner);
    virtual char getType() = 0;
    virtual int getStrength() = 0;
    virtual void move(string);
    int getC();
    void setC(char c);
    int getX();
    void setX(int i);
    int getY();
    void setY(int i);
    int getOwner();
    virtual void add(shared_ptr<BoardObjects>);
    virtual vector <shared_ptr<BoardObjects>> getOthers();
    virtual void which();
    virtual void kill() = 0;
    virtual bool isAlive() = 0;

};



#endif

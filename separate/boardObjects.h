#ifndef BOARDOBJECTS__H
#define BOARDOBJECTS__H
#include <map> 
#include <string>
#include <iostream>
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

    virtual void which();

};



#endif

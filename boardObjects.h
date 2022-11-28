#ifndef BOARDOBJECTS__H
#define BOARDOBJECTS__H
#include <map> 
#include <string>
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
    int getX();
    int getY();
    int getC();
};



#endif

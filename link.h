#ifndef LINK__H
#define LINK__H

#include <map> 
#include <string>
#include "boardObjects.h"
using namespace std;

class Link: public BoardObjects{
    int strength;
    int spaces = 1;

    public:
    Link(char c, int x, int y, int owner, int strength);
    virtual char getType() = 0;
    int getStrength() override;
};



#endif

#ifndef ABILITIES__H
#define ABILITIES__H

/* #include "link.h" */
#include <memory>
#include <iostream> 
using namespace std;

class Player;

class Abilities{
    
    public:
    virtual void useAbility(Player & p) = 0;

};


#endif

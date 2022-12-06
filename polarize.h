#ifndef POLARIZE__H
#define POLARIZE__H

#include "abilities.h"
#include "player.h"
using namespace std;

class Polarize: public Abilities{
    
    public:
    Polarize();
    virtual void useAbility(Player& b) override;
};



#endif
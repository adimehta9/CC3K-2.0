#ifndef SCAN__H
#define SCAN__H

#include "abilities.h"
#include "player.h"
using namespace std;

class Scan: public Abilities{
    
    public:
    Scan();
    virtual void useAbility(Player & b) override;
};



#endif
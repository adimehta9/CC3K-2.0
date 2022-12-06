#ifndef FIREABIL__H
#define FIREABIL__H

#include "abilities.h"
#include "player.h"
using namespace std;

class FireAbil: public Abilities{
    
    public:
    FireAbil();
    virtual void useAbility(Player & b) override;
};



#endif
#ifndef LINKBOOST__H
#define LINKBOOST__H

#include "abilities.h"
#include "player.h"
#include "boardObjects.h"
using namespace std;

class LinkBoost: public Abilities{
    
    public:
    LinkBoost();
    virtual void useAbility(Player & b) override;
};



#endif
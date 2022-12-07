#ifndef INCSTREN__H
#define INCSTREN__H

#include "abilities.h"
#include "player.h"
#include "boardObjects.h"
using namespace std;

class IncStren: public Abilities{
    
    public:
    IncStren();
    virtual void useAbility(Player & b) override;
};

#endif


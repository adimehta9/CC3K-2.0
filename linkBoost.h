#ifndef LINKBOOST__H
#define LINKBOOST__H

#include "abilities.h"
#include "link.h"
using namespace std;

class LinkBoost: public Abilities{
    
    public:
    LinkBoost();
    virtual void useAbility(Link & b) override;
};



#endif
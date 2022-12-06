#ifndef DOWNLOAD__H
#define DOWNLOAD__H

#include "abilities.h"
#include "player.h"
using namespace std;

class Download: public Abilities{
    
    public:
    Download();
    virtual void useAbility(Player & p) override;
};



#endif
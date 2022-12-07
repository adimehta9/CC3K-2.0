#include "fireAbil.h"

FireAbil::FireAbil() { }

void FireAbil::useAbility(Player & p) { 
    
    for(auto i: p.getSet()){
        if(i->getType() == 'D' || i->getType() == 'V'){
            i->add(p.getAb());
        }
    }

    p.setSet(-1, p.getAb());

}
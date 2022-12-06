#include "incStren.h"
#include <memory>

IncStren::IncStren() { }

void IncStren::useAbility(Player & p) {
    p.getAb()->setStrength(p.getAb()->getStrength()+1);
}



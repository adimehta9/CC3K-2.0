#include "polarize.h"

Polarize::Polarize() { }

void Polarize::useAbility(Player & p) {
    if(p.getAb()->getType() == 'V') p.getAb()->setType('D');
    else p.getAb()->setType('V');
}
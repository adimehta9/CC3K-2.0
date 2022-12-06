#include "linkBoost.h"
#include <memory>

LinkBoost::LinkBoost() { }

void LinkBoost::useAbility(Player & p) {
    p.getAb()->setSpaces(2);
}



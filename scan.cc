#include "scan.h"

Scan::Scan() { }

void Scan::useAbility(Player & p) {
    p.setOppLinkSet(tolower(p.getAb()->getC())-'a', p.getAb());
}
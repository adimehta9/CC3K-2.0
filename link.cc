#include "link.h"


Link::Link(char c, int x, int y, int owner, int strength): BoardObjects{c, x, y, owner}, strength{strength} {}

int Link::getStrength() { return strength; }



#include "data.h"


Data::Data(char c, int x, int y, int owner, int strength): Link{c, x, y, owner, strength} {}

char Data::getType() { return 'D'; }

int Data::getStrength() { return Link::getStrength(); }


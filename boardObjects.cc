#include "boardObjects.h"

BoardObjects::BoardObjects(char c, int x, int y, int owner) : c{c}, x{x}, y{y}, owner{owner} {}

int BoardObjects::getX() { return x; }

int BoardObjects::getY() { return y; }

int BoardObjects::getC() { return c; }




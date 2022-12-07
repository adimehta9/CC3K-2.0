#include "boardObjects.h"

BoardObjects::BoardObjects(char c, int x, int y, int owner) : c{c}, x{x}, y{y}, owner{owner}, startX{x}, startY{y} {}

int BoardObjects::getX() { return x; }

void BoardObjects::setX(int i){ x = i; }

int BoardObjects::getY() { return y; }

void BoardObjects::setY(int i) { y = i; }

int BoardObjects::getC() { return c; }

void BoardObjects::setC(char i) { c = i; }

void BoardObjects::move(string) { }

int BoardObjects::getOwner() { return owner; }

void BoardObjects::which() { cout << "Board" << endl; }

void BoardObjects::add(shared_ptr<BoardObjects>) { }

void BoardObjects::setType(char c) { }
/* vector <shared_ptr<BoardObjects>> BoardObjects::getOthers() {  } */

void BoardObjects::setSpaces(int i) { }

bool BoardObjects::isOnFire() { return false; }

void BoardObjects::setFire(bool i) { cout << "Board Object can't be set on fire" << endl; }

char BoardObjects::getFireC() { return ' '; }

void BoardObjects::setFireC(char c) { cout << "Board Object can't have fire C" << endl; }
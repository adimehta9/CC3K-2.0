#include "boardObjects.h"

BoardObjects::BoardObjects(char c, int x, int y, int owner) : c{c}, x{x}, y{y}, owner{owner} {}

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

vector <shared_ptr<BoardObjects>> BoardObjects::getOthers() {  }

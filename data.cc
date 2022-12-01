#include "data.h"


Data::Data(char c, int x, int y, int owner, int strength): Link{c, x, y, owner, strength} {}

char Data::getType() { return 'D'; }

int Data::getStrength() { return Link::getStrength(); }

void Data::which() { cout << "Test" << endl; }

void Data::move(string dir) { Link::move(dir); }

void Data::add(shared_ptr<BoardObjects> o){ Link::add(o); }

vector <shared_ptr<BoardObjects>> Data::getOthers() { return Link::others; }

bool Data::isAlive(){ return Link::alive; }

void Data::kill() { Link::alive = false; }

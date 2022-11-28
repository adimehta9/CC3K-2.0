#include "virus.h"


Virus::Virus(char c, int x, int y, int owner, int strength): Link{c, x, y, owner, strength} {}

char Virus::getType() { return 'V'; }

int Virus::getStrength() { return Link::getStrength(); }

void Virus::which() { cout << "Virus" << endl; }

void Virus::move(string dir) { Link::move(dir); }
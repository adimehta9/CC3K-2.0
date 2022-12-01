#include "virus.h"


Virus::Virus(char c, int x, int y, int owner, int strength): Link{c, x, y, owner, strength} {}

char Virus::getType() { return 'V'; }

int Virus::getStrength() { return Link::getStrength(); }

void Virus::which() { cout << "Hi" << endl; }

void Virus::move(string dir) { Link::move(dir); }

void Virus::add(shared_ptr<BoardObjects> o){ Link::add(o); }

vector <shared_ptr<BoardObjects>> Virus::getOthers(){
    return Link::others;
}

bool Virus::isAlive() { return Link::alive; }

void Virus::kill() { Link::alive = false; }
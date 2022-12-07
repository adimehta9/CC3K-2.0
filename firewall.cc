#include "firewall.h"



Firewall::Firewall(char c, int x, int y, int owner) : BoardObjects{c, x, y, owner} {  }

char Firewall::getType() { return 'F'; }

int Firewall::getStrength() { return 0; }

void Firewall::setStrength(int i) { cout << "Firewall cannot set strength" << endl; }

bool Firewall::isAlive() { return true; }

void Firewall::kill() { cout << "Firewall cannot be killed" << endl; }

/* void Firewall::add(shared_ptr<BoardObjects> o) {
    others.emplace_back(o);
} */


vector <shared_ptr<BoardObjects>> Firewall::getOthers(){
    vector <shared_ptr<BoardObjects>> v;    
    return v;
}





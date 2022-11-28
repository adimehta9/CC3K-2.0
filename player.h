#ifndef PLAYER__H
#define PLAYER__H

#include <vector>
#include <map>
#include <string>
#include "link.h"
#include "data.h"
#include "virus.h"
#include "boardObjects.h"
#include <memory>
using namespace std;

class Player{
    int dd = 0;
    int vd = 0;
    int player;
    map<char, int> abilityCount;
    vector <shared_ptr<BoardObjects>> set;
    vector <shared_ptr<Link>> linkSet;
    vector <shared_ptr<Link>> oppLinkSet {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    int abilitiesLeft = 5;
    
    public:
    Player(int player, map<char, int> abilityCount, string linkStrng);
    map<char, int> getAbilityCount();
    vector <shared_ptr<BoardObjects>> getSet();
    vector <shared_ptr<Link>> getOppLinkSet();
    void showAbilities();

    int getData();
    int getVirus();
    int getAbilitiesLeft();
    
};



#endif

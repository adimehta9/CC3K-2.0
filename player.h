#ifndef PLAYER__H
#define PLAYER__H
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "link.h"
#include "data.h"
#include "virus.h"
#include "server.h"
#include "boardObjects.h"
using namespace std;

class Player{
    int dd = 0;
    int vd = 0;
    int player;
    map<char, int> abilityCount;
    vector <shared_ptr<BoardObjects>> set;
    vector <shared_ptr<BoardObjects>> oppLinkSet {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    int abilitiesLeft = 5;
    
    public:
    Player(int player, map<char, int> abilityCount, string linkStrng);
    map<char, int> getAbilityCount();
    vector <shared_ptr<BoardObjects>> getSet();
    void setSet(int i, shared_ptr<BoardObjects> l);
    vector <shared_ptr<BoardObjects>> getOppLinkSet();
    void setOppLinkSet(int i, shared_ptr<BoardObjects> l);
    
    void showAbilities();
    void killLink(int i);
    void incData();
    void incVirus();
    int getData();
    int getVirus();
    int getAbilitiesLeft();
    void move(char l, string dir);
    
};



#endif
#ifndef PLAYER__H
#define PLAYER__H
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "abilities.h"
#include "link.h"
#include "server.h"
#include "firewall.h"
using namespace std;

class Player{
    int dd = 0;
    int vd = 0;
    int player;
    map<char, int> abilityCount;
    shared_ptr<BoardObjects> abObj;
    vector <shared_ptr<BoardObjects>> set;
    vector <shared_ptr<BoardObjects>> oppLinkSet {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    map <char, shared_ptr<Abilities>> abil;
    int abilitiesLeft = 5;
    
    public:
    Player(int player, map<char, int> abilityCount, string linkStrng, map<char, shared_ptr<Abilities>> a);
    map<char, int> getAbilityCount();
    void setAbilityCount(char c, int i);
    vector <shared_ptr<BoardObjects>> getSet();
    void setSet(int i, shared_ptr<BoardObjects> l);
    vector <shared_ptr<BoardObjects>> getOppLinkSet();
    void setOppLinkSet(int i, shared_ptr<BoardObjects> l);
    
    void showAbilities();
    shared_ptr<BoardObjects> getAb();
    void setAb(shared_ptr<BoardObjects>);
    int getPlayer();
    void killLink(int i);
    void incData();
    void incVirus();
    int getData();
    int getVirus();
    int getAbilitiesLeft();
    void setAbilitiesLeft(int i);
    void move(char l, string dir);

    shared_ptr<Abilities> getAbility(char c);
    void abilUsedBy(shared_ptr<Abilities>);
    
};



#endif
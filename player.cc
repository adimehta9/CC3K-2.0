#include "player.h"


using namespace std;


Player::Player(int player, map<char, int> abilityCount, string linkString, map<char, shared_ptr<Abilities>> a): player{player}, abilityCount{abilityCount}, abil{a} { 
    istringstream iss{linkString};
    char type;
    int strength;
    int x;
    int y=0;
    char c;
    int diff;

    if(player == 1){
        x = 0;
        c = 'a';
        diff = 1;
    } else{
        x = 7;
        c = 'A';
        diff = -1;
    }

    while (iss >> type){
        iss >> strength;
        if(y == 3 || y == 4) set.emplace_back(make_shared<Link>(static_cast<char>(c+y), x+diff, y, player, type, strength));
        else set.emplace_back(make_shared<Link>(static_cast<char>(c+y), x, y, player, type, strength));
        
        y++;
    }

    if(player == 1){
        set.emplace_back(make_shared<Server>('S', 0, 3, player));
        set.emplace_back(make_shared<Server>('S', 0, 4, player));

    } else {
        set.emplace_back(make_shared<Server>('S', 7, 3, player));
        set.emplace_back(make_shared<Server>('S', 7, 4, player));
    }

    for(auto i: set){
        for(auto j: set){
            if(i != j){
                i->add(j);
                /* cout << i->getOthers()[0]->getType(); */
                
            }
        }
    }


}


map<char, int> Player::getAbilityCount(){
    return abilityCount;
}

void Player::setAbilityCount(char c, int i){
    abilityCount[c] = i;
}


vector <shared_ptr<BoardObjects>> Player::getSet(){
    return set;
}

void Player::setSet(int i, shared_ptr<BoardObjects> l){
    set[i] = l;
}

vector <shared_ptr<BoardObjects>> Player::getOppLinkSet() {
    return oppLinkSet;
}

void Player::showAbilities(){
    map <char, string> abilityDict { {'L', "Link Boost"}, { 'F', "Firewall" }, { 'D', "Download"}, {'S', "Scan"}, {'P', "Polarize"}, {'I', "Increase Strength"} };

    for(auto i: abilityCount){
        cout << "| " << abilityDict[i.first] << " " << i.second << " | ";
    }
    cout << endl;

}

int Player::getData(){
    return dd;
}

int Player::getVirus(){
    return vd;
}

int Player::getAbilitiesLeft(){
    return abilitiesLeft;
}

void Player::move(char l, string dir){
    set[l-'a']->move(dir);
}

void Player::incData() { dd += 1; }
    
void Player::incVirus() { vd += 1; }

void Player::killLink(int i){
    set[i]->kill();
}

void Player::setOppLinkSet(int i, shared_ptr<BoardObjects> l){ oppLinkSet[i] = l; }

shared_ptr<BoardObjects> Player::getAb() { return abObj; }

void Player::setAb(shared_ptr<BoardObjects> a) { abObj = a; }

void Player::abilUsedBy(shared_ptr<Abilities> a) {
    a->useAbility(*this);
}

shared_ptr<Abilities> Player::getAbility(char c) { return abil[c]; }

int Player::getPlayer() { return player; }

void Player::setAbilitiesLeft(int i) { abilitiesLeft = i; }
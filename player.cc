#include "player.h"

using namespace std;


Player::Player(int player, map<char, int> abilityCount, string linkString): player{player}, abilityCount{abilityCount} { 
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
        if(type == 'D'){
            if(y==3 || y==4) set.emplace_back(make_shared<Data>(static_cast<char>(c+y), x+diff, y, player, strength));    
            else set.emplace_back(make_shared<Data>(static_cast<char>(c+y), x, y, player, strength));
        } else if (type == 'V'){    
            if(y==3 || y==4) set.emplace_back(make_shared<Virus>(static_cast<char>(c+y), x+diff, y, player, strength));
            else set.emplace_back(make_shared<Virus>(static_cast<char>(c+y), x, y, player, strength));
        }
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


vector <shared_ptr<BoardObjects>> Player::getSet(){
    return set;
}

vector <shared_ptr<Link>> Player::getOppLinkSet() {
    return oppLinkSet;
}

void Player::showAbilities(){
    map <char, string> abilityDict { {'L', "Link Boost"}, { 'F', "Firewall" }, { 'D', "Download"}, {'S', "Scan"}, {'P', "Polarize"} };

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
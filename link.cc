#include "link.h"
#include "boardObjects.h"
#include <exception>
#include <functional>
#include <iostream>
using namespace std;


Link::Link(char c, int x, int y, int owner, char type, int strength): BoardObjects{c, x, y, owner}, type{type}, strength{strength} {}

char Link::getType() { return type; }

int Link::getStrength() { return strength; }

int Link::getSpaces() { return spaces; }

void Link::move(string dir){
    bool p_one = false;
    if(BoardObjects::getOwner() == 1){
        p_one = true;
    }

    if(dir == "up"){
        for(auto i: others){
            if(getX() - spaces == i->getX() && getY() == i->getY()){
                throw exception();
            }
        } 
        
        if(p_one){
            if(BoardObjects::getX()-spaces < 0){
                throw exception();
            }
        }
        BoardObjects::setX(BoardObjects::getX() - spaces);
    } else if(dir == "right"){
        for(auto i: others){
            if(getX() == i->getX() && getY() + spaces == i->getY()){
                throw exception();
            }
        }

        if(BoardObjects::getY() + spaces > 7) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() + spaces);

    } else if (dir == "left"){
        for(auto i: others){
            if(getX() == i->getX() && getY() - spaces == i->getY()){
                throw exception();
            }
        }

        if(BoardObjects::getY() - spaces < 0) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() - spaces);
    } else if (dir == "down"){
        for(auto i: others){
            if(getX() + spaces == i->getX() && getY() == i->getY()){
                throw exception();
            }
        }

        if(!p_one) {
            if(BoardObjects::getX() + spaces > 7){
                throw exception();
            }
        }
        BoardObjects::setX(BoardObjects::getX() + spaces);
    } else {
        throw exception();
    }
}

void Link::which(){
    cout << "link" << endl;
}

void Link::add(shared_ptr<BoardObjects> o){
    others.emplace_back(o);
}

vector <shared_ptr<BoardObjects>> Link::getOthers(){
    return others;
}

bool Link::isAlive() { return alive; }

void Link::kill() { alive = false; }

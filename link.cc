#include "link.h"
#include "boardObjects.h"
#include "download.h"
#include <exception>
#include <functional>
#include <iostream>
using namespace std;


Link::Link(char c, int x, int y, int owner, char type, int strength): BoardObjects{c, x, y, owner}, type{type}, strength{strength} {}

char Link::getType() { return type; }

void Link::setType(char c) { type = c; }


int Link::getStrength() { return strength; }

int Link::getSpaces() { return spaces; }

void Link::setSpaces(int i) { spaces = i; }

void Link::move(string dir){
    bool p_one = false;
    if(BoardObjects::getOwner() == 1){
        p_one = true;
    }

    if(dir == "up"){
        for(auto i: others){
            if(i->isAlive()) {
                if(getX() - spaces == i->getX() && getY() == i->getY()){
                    if(i->getType() == 'F'){
                        onFire = true;
                        fireC = i->getC();
                    } else { 
                        throw exception(); 
                    }
                }
            }
        }
        
        if(p_one){
            if(BoardObjects::getX()-spaces < 0){
                throw exception();
            }
        } else if(!p_one){
            if(BoardObjects::getX() - spaces < 0){
                throw Dd();
            }
        }
        BoardObjects::setX(BoardObjects::getX() - spaces);
        onFire = false;


    } else if(dir == "right"){
        for(auto i: others){
            if(i->isAlive()) {
                if(getX() == i->getX() && getY() + spaces == i->getY()){
                    if(i->getType() == 'F'){
                        onFire = true;
                        fireC = i->getC();
                    } else {
                        throw exception();
                    }
                }
            }
        }

        if(BoardObjects::getY() + spaces > 7) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() + spaces);
        onFire = false;

    } else if (dir == "left"){
        for(auto i: others){
            if(i->isAlive()) {
                if(getX() == i->getX() && getY() - spaces == i->getY()){
                    if(i->getType() == 'F'){
                        onFire = true;
                        fireC = i->getC();
                    } else {
                        throw exception();
                    }
                }
            }
        }

        if(BoardObjects::getY() - spaces < 0) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() - spaces);
        onFire = false;
    } else if (dir == "down"){
        for(auto i: others){
            if(i->isAlive()) {
                if(getX() + spaces == i->getX() && getY() == i->getY()){
                    if(i->getType() == 'F'){
                        onFire = true;
                        fireC = i->getC();
                    } else {
                        throw exception();
                    }
                }
            }
        }

        if(!p_one) {
            if(BoardObjects::getX() + spaces > 7){
                throw exception();
            }
        } else if (BoardObjects::getX() + spaces > 7){
            throw Dd();
        }
        BoardObjects::setX(BoardObjects::getX() + spaces);
        onFire = false;
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

void Link::setStrength(int i) { strength = i; }

bool Link::isOnFire() { return onFire; }

void Link::setFire(bool i) { onFire = i; }

char Link::getFireC() { return fireC; }

void Link::setFireC(char c) { fireC = c; }
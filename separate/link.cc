#include "link.h"
#include "boardObjects.h"
#include <exception>
#include <functional>
#include <iostream>
using namespace std;


Link::Link(char c, int x, int y, int owner, int strength): BoardObjects{c, x, y, owner}, strength{strength} {}

int Link::getStrength() { return strength; }

int Link::getSpaces() { return spaces; }



// add throwing exceptions
void Link::move(string dir){
    bool p_one = false;
    if(BoardObjects::getOwner() == 1){
        p_one = true;
    }

    if(dir == "up"){
        if(p_one){
            if(BoardObjects::getX() == 0 || (BoardObjects::getX() == 1 && (BoardObjects::getY() == 3 || BoardObjects::getY() == 4))){
                throw exception();
            }
        }
        BoardObjects::setX(BoardObjects::getX() - spaces);
    } else if(dir == "right"){
        if(BoardObjects::getY() == 7) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() + spaces);

    } else if (dir == "left"){
        if(BoardObjects::getY() == 0) { throw exception(); }
        BoardObjects::setY(BoardObjects::getY() - spaces);
    } else if (dir == "down"){
        if(!p_one) {
            if(BoardObjects::getX() == 7 || (BoardObjects::getX() == 6 && (BoardObjects::getY() == 3 || BoardObjects::getY() == 4))){
                throw exception();
            }
        }
        BoardObjects::setX(BoardObjects::getX() + spaces);
    }
}

void Link::which(){
    cout << "link" << endl;
}


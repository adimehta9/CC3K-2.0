#ifndef LINK__H
#define LINK__H

#include <map> 
#include <string>
#include <memory>
#include <vector>
#include "boardObjects.h"
using namespace std;

class Link: public BoardObjects{
    protected:
    int strength;
    int spaces = 1;
    vector <shared_ptr<BoardObjects>> others;


    public:
    Link(char c, int x, int y, int owner, int strength);
    /* virtual char getType() = 0; */
    int getStrength() override;
    void move(string) override;
    void which() override;
    int getSpaces();
    virtual void add(shared_ptr<BoardObjects>);
    vector <shared_ptr<BoardObjects>> getOthers();
};



#endif

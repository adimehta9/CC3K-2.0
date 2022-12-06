#ifndef LINK__H
#define LINK__H

#include <map> 
#include <string>
#include <memory>
#include <vector>
#include "abilities.h"
#include "boardObjects.h"
using namespace std;

class Link: public BoardObjects{
    protected:
    char type;
    int strength;
    int spaces = 1;
    bool alive = true;
    vector <shared_ptr<BoardObjects>> others;



    public:
    Link(char c, int x, int y, int owner, char type, int strength);
    virtual char getType() override;
    virtual void setType(char c) override;
    int getStrength() override;
    void move(string) override;
    void which() override;
    int getSpaces();
    void setSpaces(int i) override;
    virtual void add(shared_ptr<BoardObjects>) override;
    vector <shared_ptr<BoardObjects>> getOthers() override;
    bool isAlive() override;
    void kill() override;
    

};



#endif

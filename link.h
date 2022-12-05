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
    /* virtual char getType() = 0; */
    virtual char getType() override;
    int getStrength() override;
    void move(string) override;
    void which() override;
    int getSpaces();
    void setSpaces(int i);
    virtual void add(shared_ptr<BoardObjects>) override;
    vector <shared_ptr<BoardObjects>> getOthers() override;
    bool isAlive() override;
    void kill() override;


    void abilityBy(shared_ptr<Abilities> a) override;
    

};



#endif

#include "boardObjects.h"
#ifndef FIREWALL__H
#define FIREWALL__H

class Firewall: public BoardObjects {
    /* vector <shared_ptr<BoardObjects>> others; */


    public:
    Firewall(char c, int x, int y, int owner);
    virtual char getType() override;
    virtual int getStrength() override;
    virtual void setStrength(int i) override;
    virtual bool isAlive() override;
    virtual void kill() override;
    virtual vector <shared_ptr<BoardObjects>> getOthers() override;
    /* virtual void add(shared_ptr<BoardObjects>) override; */


    
};





#endif
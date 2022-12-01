#ifndef VIRUS__H
#define VIRUS__H

#include "link.h"
using namespace std;

class Virus: public Link{

    public:
    Virus(char c, int x, int y, int owner, int strength);
    char getType() override;
    int getStrength() override;
    void which() override;
    void move(string) override;
    bool isAlive() override;
    void kill() override;
    void add(shared_ptr<BoardObjects>);
    vector <shared_ptr<BoardObjects>> getOthers();
};



#endif
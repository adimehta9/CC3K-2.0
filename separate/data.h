#ifndef DATA__H
#define DATA__H

#include "link.h"
using namespace std;

class Data: public Link{

    public:
    Data(char c, int x, int y, int owner, int strength);
    char getType() override;
    int getStrength() override;
    void which() override;
    void move(string) override;
    

};



#endif
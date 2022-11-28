#ifndef VIRUS__H
#define VIRUS__H

#include "link.h"
using namespace std;

class Virus: public Link{

    public:
    Virus(char c, int x, int y, int owner, int strength);
    char getType() override;
    int getStrength();
};



#endif

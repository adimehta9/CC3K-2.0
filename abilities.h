#ifndef ABILITIES__H
#define ABILITIES__H

/* #include "link.h" */
#include <memory>
using namespace std;

class Link;

class Abilities{
    
    public:
    
    virtual void useAbility(Link & l) = 0;
    /* virtual void useAbility(shared_ptr<Firewall> b) = 0; */


};


#endif
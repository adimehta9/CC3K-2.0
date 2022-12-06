#ifndef SERVER__H
#define SERVER__H

#include <vector>
#include <map>
#include <string>
#include "boardObjects.h"
#include <memory>
using namespace std;

class Server: public BoardObjects{
    

    public:
    Server(char c, int x, int y, int owner);
    char getType() override;
    int getStrength() override;
    void setStrength(int i) override;
    bool isAlive() override;
    void kill() override;
    vector <shared_ptr<BoardObjects>> getOthers() override;

};



#endif
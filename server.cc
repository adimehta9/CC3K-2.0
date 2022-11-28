#include "server.h"



Server::Server(char c, int x, int y, int owner) : BoardObjects{c, x, y, owner} {}


char Server::getType(){
    return 'S';
}

int Server::getStrength() {
    return 0;
}

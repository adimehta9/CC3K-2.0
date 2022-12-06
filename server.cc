#include "server.h"



Server::Server(char c, int x, int y, int owner) : BoardObjects{c, x, y, owner} {}


char Server::getType(){
    return 'S';
}

int Server::getStrength() {
    return 0;
}

void Server::setStrength(int i) { }

bool Server::isAlive() {
    return true;
}

void Server::kill() { };

vector <shared_ptr<BoardObjects>> Server::getOthers(){
    vector <shared_ptr<BoardObjects>> v;
    return v;
}

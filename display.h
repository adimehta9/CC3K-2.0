
#ifndef DISPLAY__H
#define DISPLAY__H

#include <vector>
#include "link.h"
#include <memory>
using namespace std;


class Display{

    vector<vector<char>> display;

    

    public:
    Display();
    void showBoard();
    void notify(shared_ptr<BoardObjects> subject);


    virtual ~Display();
};



#endif
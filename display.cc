#include <iostream>
#include "display.h"
#include <vector>

Display::Display(){
    for(int i=0; i<8; i++){
        vector<char> vect;
        for(int j=0; j<8; j++){
            vect.emplace_back('.');
        }
        display.emplace_back(vect);
    }
}

Display::~Display(){}


void Display::showBoard(){
    for(int i=0; i<8; i++){
        cout << "=";
    }
    cout << endl;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << display[i][j];
        }
        cout << endl;
    }
    for(int i=0; i<8; i++){
        cout << "=";
    }
    cout << endl;

}

void Display::notify(shared_ptr<BoardObjects> subject){
    display[subject->getX()][subject->getY()] = subject->getC();
}

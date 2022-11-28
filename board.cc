#include "board.h"
#include <iostream>
#include <memory>
using namespace std;


Board::Board(shared_ptr<Player> one, shared_ptr<Player> two, bool graphics) : one{one}, two{two}, graphics{graphics} {

    dis = make_shared<Display>();
    
    for(auto i: one->getSet()) {
        dis->notify(i);
    }
    
    for(auto i: two->getSet()) {
        dis->notify(i);
    }
    


    if(graphics){
        /* graph = make_shared<Graphics>(); */
    }

}



void Board::showBoard(bool one_turn){
    cout << endl;
    cout << "======================================" << endl;

    cout << "Player 1: " << endl;
    if(one_turn){
        cout << "Downloaded: " << one->getData() << "D, " << one->getVirus() << "V" << endl;
        cout << "Abilities: " << one->getAbilitiesLeft() << endl;
        
        int temp = 0;
        
        for(auto i: one->getSet()){
            if(i->getType() == 'S') { continue; }
            cout << static_cast<char>('a' + temp) << ": " << static_cast<char>(i->getType()) << i->getStrength() << " ";
            if(temp == 3){ cout << endl; }
            temp++;
        }
        
        cout << endl;
        dis->showBoard();
        cout << "Player 2:" << endl;
        cout << "Downloaded: " << two->getData() << "D, " << two->getVirus() << "V" << endl;
        cout << "Abilities: " << two->getAbilitiesLeft() << endl;
 
        temp = 0;

        for(auto i: one->getOppLinkSet()){
            cout << static_cast<char>('A' + temp) << ": "; 
            
            if(i == nullptr){
                cout << "? ";
            } else {
                cout << static_cast<char>(i->getType()) << i->getStrength() << " ";
            }

            if(temp == 3) cout << endl;
            temp++;
        }

        cout << endl;
        cout << "======================================" << endl;
        cout << endl;
    } else{
        cout << "Downloaded: " << one->getData() << "D, " << one->getVirus() << "V" << endl;
        cout << "Abilities: " << one->getAbilitiesLeft() << endl;
        
        int temp = 0;

         for(auto i: two->getOppLinkSet()){
            cout << static_cast<char>('a' + temp) << ": "; 
            
            if(i == nullptr){
                cout << "? ";
            } else {
                cout << static_cast<char>(i->getType()) << i->getStrength() << " ";
            }
            if(temp == 3) cout << endl;
            temp++;
        }

        cout << endl;
        
        dis->showBoard();
        cout << "Player 2:" << endl;
        cout << "Downloaded: " << two->getData() << "D, " << two->getVirus() << "V" << endl;
        cout << "Abilities: " << two->getAbilitiesLeft() << endl;
 
        temp = 0;
        for(auto i: two->getSet()){
            if(i->getType() == 'S') continue;
            cout << static_cast<char>('A' + temp) << ": " << static_cast<char>(i->getType()) << i->getStrength() << " ";
            if(temp == 3){ cout << endl; }
            temp++;
        }

        cout << endl;
        cout << "======================================" << endl;
        cout << endl;


    }

    if(graphics){
        /* graph->showBoard(); */
    }
}


void Board::move(char l, string dir, bool one_turn){
    shared_ptr<Player> p;
    if(one_turn){
        p = one;
    } else{
        p = two;
    }

    shared_ptr<BoardObjects> b =  p->getSet()[tolower(l)-'a'];
    b->setC('.');
    dis->notify(b);
    p->move(l, dir);
    b->setC(l);
    dis->notify(b);
    showBoard(!one_turn);
}













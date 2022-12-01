#include "board.h"
#include <exception>
#include <iostream>
#include <memory>
using namespace std;

Board::Board(shared_ptr<Player> one, shared_ptr<Player> two, bool graphics)
    : one{one}, two{two}, graphics{graphics} {

  dis = make_shared<Display>();

  for (auto i : one->getSet()) {
    dis->notify(i);
  }

  for (auto i : two->getSet()) {
    dis->notify(i);
  }

  if (graphics) {
    /* graph = make_shared<Graphics>(); */
  }
}

void Board::showBoard() {
  cout << endl;
  cout << "======================================" << endl;

  cout << "Player 1: " << endl;
  if (one_turn) {
    cout << "Downloaded: " << one->getData() << "D, " << one->getVirus() << "V"
         << endl;
    cout << "Abilities: " << one->getAbilitiesLeft() << endl;

    int temp = 0;

    for (auto i : one->getSet()) {
      if (i->getType() == 'S') {
        continue;
      }
      cout << static_cast<char>('a' + temp) << ": "
           << static_cast<char>(i->getType()) << i->getStrength() << " ";
      if (temp == 3) {
        cout << endl;
      }
      temp++;
    }

    cout << endl;
    dis->showBoard();
    cout << "Player 2:" << endl;
    cout << "Downloaded: " << two->getData() << "D, " << two->getVirus() << "V"
         << endl;
    cout << "Abilities: " << two->getAbilitiesLeft() << endl;

    temp = 0;

    for (auto i : one->getOppLinkSet()) {
      cout << static_cast<char>('A' + temp) << ": ";

      if (i == nullptr) {
        cout << "? ";
      } else {
        cout << static_cast<char>(i->getType()) << i->getStrength() << " ";
      }

      if (temp == 3)
        cout << endl;
      temp++;
    }

    cout << endl;
    cout << "======================================" << endl;
    cout << endl;
  } else {
    cout << "Downloaded: " << one->getData() << "D, " << one->getVirus() << "V"
         << endl;
    cout << "Abilities: " << one->getAbilitiesLeft() << endl;

    int temp = 0;

    for (auto i : two->getOppLinkSet()) {
      cout << static_cast<char>('a' + temp) << ": ";

      if (i == nullptr) {
        cout << "? ";
      } else {
        cout << static_cast<char>(i->getType()) << i->getStrength() << " ";
      }
      if (temp == 3)
        cout << endl;
      temp++;
    }

    cout << endl;

    dis->showBoard();
    cout << "Player 2:" << endl;
    cout << "Downloaded: " << two->getData() << "D, " << two->getVirus() << "V"
         << endl;
    cout << "Abilities: " << two->getAbilitiesLeft() << endl;

    temp = 0;
    for (auto i : two->getSet()) {
      if (i->getType() == 'S')
        continue;
      cout << static_cast<char>('A' + temp) << ": "
           << static_cast<char>(i->getType()) << i->getStrength() << " ";
      if (temp == 3) {
        cout << endl;
      }
      temp++;
    }

    cout << endl;
    cout << "======================================" << endl;
    cout << endl;
  }

  if (graphics) {
    /* graph->showBoard(); */
  }
}

// p downloads l
void Board::download(shared_ptr<BoardObjects> l, shared_ptr<Player> p){
  if(l->getType() == 'V'){
    p->incVirus();
  } else if (l->getType() == 'D'){
    p->incData();
  }
}

shared_ptr<Player> Board::battleCheck(shared_ptr<Player> p, shared_ptr<Player> op, shared_ptr<BoardObjects> l){
  vector<shared_ptr<BoardObjects>> v = op->getSet();
  for(auto i: v){
    if(i->isAlive()){
      if(l->getX() == i->getX() && l->getY() == i->getY()){
        if(i->getType() == 'S'){
          download(l, op);
          /* p->setSet(tolower(l->getC())-'a', nullptr); */
          p->killLink(tolower(l->getC())-'a');
          p->setOppLinkSet(tolower(l->getC())-'a', i);
          op->setOppLinkSet(tolower(l->getC())-'a', l);
          return op;
        } else if (l->getStrength() >= i->getStrength()){
          download(i, p);
          /* op->setSet(tolower(l->getC())-'a', nullptr); */
          op->killLink(tolower(l->getC())-'a');
          p->setOppLinkSet(tolower(l->getC())-'a', i);
          op->setOppLinkSet(tolower(l->getC())-'a', l);
          return p;
        } else {
          download(l, op);
          /* p->setSet(tolower(l->getC())-'a', nullptr); */
          p->killLink(tolower(l->getC())-'a');
          p->setOppLinkSet(tolower(l->getC())-'a', i);
          op->setOppLinkSet(tolower(l->getC())-'a', l);
          return op;
        }
      }
    }
  }
  return nullptr;
}

void Board::move(char l, string dir) {

  try {
    char temp = tolower(l);
    shared_ptr<Player> p;
    shared_ptr<Player> op;
    if (one_turn) {
      p = one;
      op = two;
      l = temp;
    } else {
      p = two;
      op = one;
      l = toupper(l);
    }

    shared_ptr<BoardObjects> b = p->getSet()[temp - 'a'];
    if(b->isAlive() == false){
      throw exception();
    }
    b->setC('.');
    dis->notify(b);
    p->move(temp, dir);
    b->setC(l);

    shared_ptr<Player> winner = battleCheck(p, op, b);
    

    if(winner == nullptr || winner == p){
      dis->notify(b);
    }

    /* for(auto i: two->getSet()){
      if(i == nullptr){ cout << "Hi" << endl; } 
      else cout << i->getType();
    } */
    cout << endl;

    one_turn = !one_turn;
    
    showBoard();


  } catch (exception &e){
    cout << endl << "Invalid Move" << endl;
    cout << "Try again s" << endl << endl;
  }
}


void Board::showAbilities() {
  if (one_turn) {
    cout << "Player One's Abilities:" << endl;
    one->showAbilities();
  } else {
    cout << "Player Two's Abilities:" << endl;
    two->showAbilities();
  }
}

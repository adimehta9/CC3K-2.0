#include "board.h"
#include "display.h"
#include "player.h"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string cur;
  string ability1 = "LFDSP"; // Default abilities
  string ability2 = "LFDSP"; // Default abilities
  string link1 = "";         // Link configuration as string
  string link2 = "";         // Link configuration as string
  map<char, int> abilityCount1{
      {'L', 1}, {'F', 1}, {'D', 1}, {'S', 1}, {'P', 1}};
  map<char, int> abilityCount2{
      {'L', 1}, {'F', 1}, {'D', 1}, {'S', 1}, {'P', 1}};
  bool graphics = false;

  // randomize link1 and link 2
  vector<string> all_links = {"D1", "D2", "D3", "D4", "V1", "V2", "V3", "V4"};
  int max = 8;

  do {
    int ele = rand() % max;
    link1 += all_links[ele] + ' ';
    max -= 1;
    string temp = all_links[ele];
    all_links[ele] = all_links[max];
    all_links[max] = temp;
  } while (max != 0);

  max = 8;
  do {
    int ele = rand() % max;
    link2 += all_links[ele] + ' ';
    max -= 1;
    string temp = all_links[ele];
    all_links[ele] = all_links[max];
    all_links[max] = temp;
  } while (max != 0);

  for (int i = 1; i < argc; i++) {
    cur = argv[i];
    if (cur == "-ability1") {
      abilityCount1.clear();
      i++;
      ability1 = argv[i];
      istringstream iss{ability1};
      char abil;

      while (iss >> abil) {
        abilityCount1[abil] = abilityCount1[abil] + 1;

        /* cout << abil << " is " << repeat[abil] << endl; */

        if (abilityCount1[abil] > 2) {
          cout << "Cannot have more than 2 of same ability" << endl;
          return 1; // change to exception handling later
        }
      }
    } else if (cur == "-ability2") {
      abilityCount2.clear();
      i++;
      ability2 = argv[i];
      istringstream iss{ability2};
      char abil;

      while (iss >> abil) {
        abilityCount2[abil] = abilityCount2[abil] + 1;

        if (abilityCount2[abil] > 2) {
          cout << "Cannot have more than 2 of same ability" << endl;
          return 1; // change to exception handling later
        }
      }

    } else if (cur == "-link1") {
      i++;
      ifstream ls1{argv[i]};
      getline(ls1, link1);
      cout << "Player one's links are " << link1 << endl;
    } else if (cur == "-link2") {
      i++;
      ifstream ls2{argv[i]};
      getline(ls2, link2);
    } else if (cur == "-graphics") {
      graphics = true;
    }
  }

  shared_ptr<Player> one = make_shared<Player>(1, abilityCount1, link1);
  shared_ptr<Player> two = make_shared<Player>(2, abilityCount2, link2);
  shared_ptr<Board> board = make_shared<Board>(one, two, graphics);

  board->showBoard();

  while (getline(cin, cur)) {
    istringstream iss{cur};
    iss >> cur;
    if (cur == "move") {
      char l;
      string dir;
      iss >> l;
      iss >> dir;
      board->move(l, dir);
      /* one_turn = !one_turn; */
    } else if (cur == "abilities") {
      cout << endl;
      board->showAbilities();
      cout << endl;

    } else if (cur == "ability") {

    } else if (cur == "board") {
      cout << endl;
      board->showBoard();
      cout << endl;

    } else if (cur == "sequence") {

    } else if (cur == "quit") {
      break;
    }
  }
}

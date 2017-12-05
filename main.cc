#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "score.h"
#include "upcoming.h"
#include "board.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"
#include "blockselector.h"
#include "gameover.h"

using namespace std;

// Necessary to initialize the Score singleton
Score *Score::singleton_instance = 0;
Upcoming *Upcoming::singleton_instance = 0;

static void inputHelper(Board *obj, Block *&b, string command, int level, int &i,
                        bool usingseed, int seed) {
  bool changelvl = false;

  const string left = "lef";//left(lef)
  const string right = "ri";//right(ri)
  const string down = "do";//down(do)
  const string cw = "cl";//clockwise(cl)
  const string ccw = "co";//counterclockwise(co)
  const string drop = "dr";//drop(dr)
  const string levelup = "levelu";//levelup(levelu)
  const string leveldown = "leveld";//leveldown(leveld)
  const string norandom = "n";//norandom(n)
  const string random = "ra";//random(ra)
  const string sequence = "s"; //sequence fiel(s)
  const string restart = "re";//restart(re)
  const string hint = "h";//hint(h)

  if (left == command.substr(0,3)) {
    b->moveLeft();
  } else if (right == command.substr(0,2)) {
    b->moveRight();
  } else if (down == command.substr(0,2)) {
    b->moveDown();
  } else if (cw == command.substr(0,2)) {
    b->clockwise();
  } else if (ccw == command.substr(0,2)) {
    b->antiClockwise();
  } else if (drop == command.substr(0,2)) {
    //while (obj->getDown()) {
    for (int z = 0; z < 15; z++) {
      b->moveDown();
    }
    obj->setDown();
    obj->notifyObservers();

    if (changelvl) {
      changelvl = false;

      Upcoming::instance()->setlevel(level);
      Upcoming::instance()->updatenextblock(level, seed, usingseed, obj);
    }

    ++i;
    b = Upcoming::instance()->getVecBlock().at(i);
    b->init();
  } else if (levelup == command.substr(0,6)) {
    level++;

    if (level >= 4) {
      level = 4;
    }

    changelvl = true;
  } else if (leveldown == command.substr(0,6)) {
    level--;

    if (level <= 0) {
      level = 0;
    }

    changelvl = true;
  } else if (norandom == command.substr(0,1)) {
    string file;
    cin >> file;
    //usingrandom = false;
  } else if (random == command.substr(0,2)) {
    //usingrandom = true;
  } else if (sequence == command.substr(0,1)) {
    string seqfile;
    cin >> seqfile;
    ifstream f{seqfile};

    string commands;

    while (f >> commands) {
      istringstream ss{commands};
      int mult;

      if (ss >> mult) {
        ss >> command;
        for (int i = 0; i < mult; i++) {
          inputHelper(obj, b, command, level, i, usingseed, seed);
        }
      } else {
        ss >> command;
        inputHelper(obj, b, command, level, i, usingseed, seed);
      }
    }
  } else if (restart == command.substr(0,2)) {
    obj->init();
  } else if (hint == command.substr(0,1)) {
    //hint
  } else if (command == "I") {
    b = new IBlock(obj);
    b->init();
  } else if (command == "J") {
    b = new JBlock(obj);
    b->init();
  } else if (command == "L") {
    b = new LBlock(obj);
    b->init();
  } else if (command == "O") {
    b = new OBlock(obj);
    b->init();
  } else if (command == "S") {
    b = new SBlock(obj);
    b->init();
  } else if (command == "T") {
    b = new TBlock(obj);
    b->init();
  } else if (command == "Z") {
    b = new ZBlock(obj);
    b->init();
  }
}

int main(int argc, char *argv[]) {
  // PROCESS COMMAND LINE FLAGS
  //bool text = false;
  bool usingseed = false;
  int seed = -1;
  //bool fileused = false;
  string filename = "sequence.txt";
  int level = 0;

  for (int x = 1; x < argc; ++x) {
    if (string(argv[x]), "-text") {
      //text = true; //using textdisplay
    } else if (string(argv[x]) == "-seed") {
      istringstream ss{argv[x+1]};
      if (!(ss >> seed)) {
        cerr << "Please enter a correct seed" << endl;
        return 1;
      }

      usingseed = true;
    } else if (string(argv[x]) == "-scriptfile" ) {
      //fileused = true;
      filename = string(argv[x+1]);
    } else if (string(argv[x]) == "-startlevel") {
      istringstream ss{argv[x+1]};
      if (!(ss>>level)) {
        cerr << "Please enter a correct level" << endl;
        return 1;
      } else if (level > 4 || level < 0) {
        cerr << "Please enter a valid level" << endl;
        return 1;
      }
    }
  }



  // INITIALIZE BOARD AND OTHERS
  Board *obj = new Board{18, 11, -1};
  obj->init();
  Blockselector *bsl = new Blockselector{filename, level};
  bsl->runlevel(obj);
  Upcoming::instance()->updatenextblock(level, seed, usingseed, obj);
  Upcoming::instance()->setlevel(level);

  Block *b = Upcoming::instance()->getVecBlock().at(0);
  b->init();

  cout << *obj << endl;



  // START COMMAND LOOP
  string s;
  int i = 0;
  while (i < int(Upcoming::instance()->getVecBlock().size())) {
    try {
      while(cin >> s) {
        istringstream ss{s};
        int mult;
        string command;
        if (ss >> mult) {
          ss >> command;
          for (int j = 0; j < mult; j++) {
            inputHelper(obj, b, command, level, i, usingseed, seed);
          }
        } else {
          inputHelper(obj, b, s, level, i, usingseed, seed);
        }

        cout << *obj << endl;
      }
    } catch (GameOver) {
      cout << "Game Over!" << endl;
      cout << "Your high score was " << Score::instance()->getHiScore() << endl;
      break;
    }
  }

  return 0;
}

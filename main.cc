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


using namespace std;

// Necessary to initialize the Score singleton
Score *Score::singleton_instance = 0;
Upcoming *Upcoming::singleton_instance = 0;

static void inputHelper(Board *obj, Block *b, string command, int level, int &i,
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
 //   cout<<"the command is "<<command;
 //   cout<<"comapring this is"<<command.compare(0,3,right);
    if (command.compare(0,3,left) == 1) {
        b->moveLeft();
    } else if (command.compare(0,3,right)== 1) {

//	    cout<<"moving right";
        b->moveRight();
    } else if (command.compare(0,2,down)== 1) {
        b->moveDown();
    } else if (command.compare(0,2,cw) == 1) {
        b->clockwise();
    } else if (command.compare(0,2,ccw)== 1 ) {
        b->antiClockwise();
    } else if (command.compare(0,2,drop) == 1) {
        while(obj->getDown()){
            b->moveDown();
        }

        if (changelvl) {
            changelvl = false;

            Upcoming::instance()->setlevel(level);
          //  v = Upcoming::instance()->getVecBlock();
            Upcoming::instance()->updatenextblock(level, seed, usingseed, obj);
        }

        ++i;
        b = Upcoming::instance()->getVecBlock().at(i);
        b->init();
    } else if (command.compare(0,6,levelup) == 1) {
        level++;

        if (level >= 4) {
            level = 4;
        }

        changelvl = true;
    } else if (command.compare(0,6,leveldown) == 1) {
        level--;

        if (level <= 0) {
            level = 0;
        }

        changelvl = true;
    } else if (command.compare(0,1,norandom) == 1) {
        string file;
        cin >> file;
        //usingrandom = false;
    } else if (command.compare(0,2,random) == 1) {
        //usingrandom = true;
    } else if (command.compare(0,1,sequence) == 1) {
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
    } else if (command.compare(0,2,restart) == 1) {
        //restart grid
    } else if (command.compare(0,1,hint) == 1) {
        //hint
    } else if (command.compare(0,1,"I") == 1) {
        //insert I block
    } else if (command.compare(0,1,"J") == 1) {
        //insert J block
    } else if (command.compare(0,1,"O") == 1) {
        //insert O block
    } else if (command.compare(0,1,"S") == 1) {
        //insert S block
    } else if (command.compare(0,1,"Z") == 1) {
        //insert Z block
    } else if (command.compare(0,1,"T") == 1) {
        //insert T block
    } else if (command.compare(0,1,"L") == 1) {
        //insert L block
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

  bool firstblock = true;
  Block *b = Upcoming::instance()->getVecBlock().at(0);
  if (firstblock) {
    firstblock = false;
    b->init();
  }
  cout << *obj;



  // START COMMAND LOOP
  string s;
  int i = 0;
  while (i < int(Upcoming::instance()->getVecBlock().size())) {
    cout << *obj;

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

      cout << *obj;
    }
  }
}

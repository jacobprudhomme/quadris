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

using namespace std;

// Necessary to initialize the Score singleton
Score *Score::singleton_instance = 0;
Upcoming *Upcoming::singleton_instance = 0;


int main(int argc, char *argv[]) {
    int level = 0;
    bool text = false;
    bool usingseed = false;
    int seed;
    bool fileused = false;
    string filename;
    bool usingrandom = true;
/*
    for(int x = 1; x < argc; ++x){
        if (argv[x] == "-text"){
             text = true;
        } else if (argv[x] == "-seed"){
            istringstream iss {argv[x+1]};
            if (!(iss>>seed)){
                "Please enter a correct seed";
                return 1;
            }
            usingseed = true;
            ++x;
        } else if (argv[x] == "-scriptfile" ){
            fileused = true;
                filename = argv[x+1];
            ++x;
        } else if (argv[x] == "-startlevel"){
            istringstream iss {argv[x+1]};
            if (!(iss>>level)){
                "Please enter a correct level";
                return 1;
            } else if (level > 4 || level < 0) {
                "Please enter a valid level";
            }
            ++x;
        }
    }
*/
    
    char mult;
    string left = "lef";//left(lef)
    string right = "ri";//right(ri)
    string down = "do";//down(do)
    string cw = "cl";//clockwise(cl)
    string ccw = "co";//counterclockwise(co)
    string drop = "dr";//drop(dr)
    string levelup = "levelu";//levelup(levelu)
    string leveldown = "leveld";//leveldown(leveld)
    string norandom = "n";//norandom(n)
    string random = "ra";//random(ra)
    string sequence = "s"; //sequence fiel(s)
    string restart = "re";//restart(re)
    string hint = "h";//hint(h)
    string s;
    string file;
    string seqfile;

    Board *obj = new Board{18, 11, 0};
    obj->init();
    JBlock i(obj);
    cout << (*obj) << endl;
    i.moveLeft();
    cout << (*obj) << endl;    
    /*
    while (cin >> s) {
        istringstream iss{s};
        iss >> mult;

        if (s.compare(0,3,left) == 0) {
           //move left
        } else if (s.compare(0,2,right) == 0) {
          //move right
        } else if (s.compare(0,2,down) == 0) {
            //move down
        } else if (s.compare(0,2,cw) == 0) {

        } else if (s.compare(0,2,ccw) == 0) {

        } else if (s.compare(0,2,drop) == 0) {

        } else if (s.compare(0,6,levelup) == 0) {
            if (mult >= 0) {
              level += mult;
            }

            if (level >= 4) {
              level = 4;
            }

        } else if (s.compare(0,6,leveldown) == 0) {
            if (mult >= 0) {
                level -= mult;
            }

            if (level <= 0) {
                level = 0;
            }
        } else if (s.compare(0,1,norandom) == 0) {
          cin >> file;
          usingrandom = false;
        } else if (s.compare(0,2,random) == 0) {
            usingrandom = true;
        } else if (s.compare(0,1,sequence) == 0) {
            cin >> seqfile;
            ifstream f{seqfile};

            string commands;

            while (f>>commands) {
              istringstream isss{commands};
              while (isss >> s) {

                  if (iss >> mult) {

                  }

                  if (s.compare(0,3,left) == 0) {
                      //move left
                  } else if (s.compare(0,2,right) == 0) {
                      //move right
                  } else if (s.compare(0,2,down) == 0) {
                      //move down
                  } else if (s.compare(0,2,cw) == 0) {

                  } else if (s.compare(0,2,ccw) == 0) {

                  } else if (s.compare(0,2,drop) == 0) {

                  } else if (s.compare(0,6,levelup) == 0) {
                      if (mult >= 0) {
                          level += mult;
                      }

                      if (level >= 4) {
                          level = 4;
                      }
                  } else if (s.compare(0,6,leveldown) == 0) {
                      if (mult >= 0) {
                          level -= mult;
                      }

                      if (level <= 0) {
                          level = 0;
                      }
                  } else if (s.compare(0,1,norandom) == 0) {
                      cin >> file;
                      usingrandom = false;
                  } else if (s.compare(0,2,random) == 0) {
                      usingrandom = true;
                  } else if (s.compare(0,2,restart) == 0) {

                  } else if (s.compare(0,1,hint) == 0) {

                  } else if (s.compare(0,1,"I") == 0) {

                  } else if (s.compare(0,1,"J") == 0) {

                  } else if (s.compare(0,1,"O") == 0) {

                  } else if (s.compare(0,1,"S") == 0) {

                  } else if (s.compare(0,1,"Z") == 0) {

                  } else if (s.compare(0,1,"T") == 0) {

                  } else if (s.compare(0,1,"L") == 0) {

                  }
              }
            }


        } else if (s.compare(0,2,restart) == 0) {
              //restart grid
        } else if (s.compare(0,1,hint) == 0) {
             //hint
        } else if (s.compare(0,1,"I") == 0) {
            //insert I block
        } else if (s.compare(0,1,"J") == 0) {
               //insert J block
        } else if (s.compare(0,1,"O") == 0) {
            //insert O block
        } else if (s.compare(0,1,"S") == 0) {
            //insert S block
        } else if (s.compare(0,1,"Z") == 0) {
             //insert Z block
        } else if (s.compare(0,1,"T") == 0) {
             //insert T block
        } else if (s.compare(0,1,"L") == 0) {
               //insert L block
        }

    }
     */
}

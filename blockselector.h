#ifndef BLOCKSELECTOR_H
#define BLOCKSELECTOR_H
#include <string>
#include "upcoming.h"
#include "board.h"

class Board;

using namespace std;

class Blockselector {
    string file0;
    int level;
    
    public:
    Blockselector(string f1, int x);
    int getlevel();
    string getfile0();
    void runlevel(Board *obj);
};

#endif
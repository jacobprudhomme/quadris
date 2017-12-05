#ifndef BLOCKSELECTOR_H
#define BLOCKSELECTOR_H

#include <string>
#include "upcoming.h"
#include "board.h"

class Board;

class Blockselector {
  std::string file0;
  int level;

  public:
    Blockselector(std::string f1, int x);

    int getlevel();
    std::string getfile0();
    
    void runlevel(Board *obj);
};

#endif

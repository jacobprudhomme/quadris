#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

#include "block.h"
#include "observer.h"


class Cell : public Observer {
  int r; //which row is this at
  int c; //which column is it at
  bool containsBlock; //does it contain a block or not
  std::string block; //tracking which type of block we have right now i, j, l...... "N" for not any block
  int numBlock; //for scoring, to see if we add score in the right way
  int level; //which level are we on, for calculating scores
  //I may be wrong, edit how you feel or I think we should have all this in state

public:
  Cell(int r, int c, bool b, std::string block, int n, int l);

  bool isBlock(); // returns true if the cell contains block or not
  void toggle(); // changes the containsblock clock switch
  void notify(Subject &whoFrom) override;// My neighbours will call this
                                                // when they've changed state
  int getR();
  int getC();
  std::string getStr();
  int getBlockNum();
  int getLevel();
  void setBlockNum(int n);
  void setbool(bool x);
};
#endif

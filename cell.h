#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "Block.h"


class Cell {
  int r; //which row is this at
  int c; //which column is it at
  bool containsBlock; //does it contain a block or not
  std::string block; //tracking which type of block we have right now i, j, l......
  int numBlock; //for scoring, to see if we add score in the right way
  int level; //which level are we on, for calculating scores
  //I may be wrong, edit how you feel or I think we should have all this in state

public:
  Cell(int r, int c, bool b, std::string str, int n, int l);

  bool isBlock(); // returns true if the cell contains block or not
  void notify(Block &whoFrom) override;// My neighbours will call this
                                                // when they've changed state
  int getX();
  int getY();
  int getbool();
  std::string getStr();
  int getBlockNum();
  int getLevel();
  void setbool(bool isBlock);
};
#endif

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "display.h"


class Board {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  Display *td = nullptr; // The text display.

 public:
  ~Board();
  void init(int rows, int columns); // Sets up an width x height grid.  Clears old grid, if necessary.
  std::vector<int> whichRowFull(); //checks if any row is full and returns all the rows number

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

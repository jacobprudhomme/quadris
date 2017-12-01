#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "display.h"
#include "cell.h"
#include "score.h"


class Board {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer *ob = nullptr;  // Another observer (intent:  graphics)

 public:
  ~Board();

  void setObserver(Observer *ob);
  void init(int rows, int columns); // Sets up an width x height grid.  Clears old grid, if necessary.
  std::vector<int> whichRowFull(); //checks if any row is full and returns all the rows number
                                  //updates scores in this, Also keep track of the moving down
  bool isFull() const;
  void notify(Subject &whoFrom); //the block is sent to make changes to the entire grid

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <cstddef>

#include "textdisplay.h"
#include "cell.h"

class Cell;

class Board {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer *ob = nullptr;  // Another observer (intent:  graphics)
  int rows;
  int cols;
  int numBlock;

 public:
  ~Board();

  void setObserver(Observer *ob);
  void init(int rows, int columns); // Sets up an width x height grid.  Clears old grid, if necessary.
  void whichRowFullDelete(); //checks if any row is full and delet all the rows and move everything
                             //downwards
  bool isFull() const;
  void notify(Subject &whoFrom); //the block is sent to make changes to the entire grid

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

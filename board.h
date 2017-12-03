#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <cstddef>
#include "textdisplay.h"
#include "cell.h"

class Cell;

class Board : public Observer, public Subject {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer *ob = nullptr;  // Another observer (intent:  graphics)
  int rows;
  int cols;
  int numBlock;

 public:
  ~Board();
  Board(int r, int c, int n);
  void setObserver(Observer *ob);
  void init(); // Sets up an width x height grid.  Clears old grid, if necessary.
  void whichRowFullDelete(); //checks if any row is full and delet all the rows and move everything
                             //downwards
  bool isFull();
  void notify(Subject &whoFrom); //the block is sent to make changes to the entire grid
  std::vector<std::vector<Cell>> getBoard();
  
  Info getInfo();
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

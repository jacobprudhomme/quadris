#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "textdisplay.h"
#include "observer.h"
#include "info.h"

class Cell;

class Board : public Observer, public Subject {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer *ob = nullptr;  // Another observer (intent:  graphics)
  int rows;
  int cols;
  int numBlock;
  void calculatingScore(std::vector<int> v);
  void deleteRows(std::vector<int> v);
  bool down;

 public:
  ~Board();
  Board(int r, int c, int n);
  void setObserver(Observer *ob);
  void init(); // Sets up an width x height grid.  Clears old grid, if necessary.
  std::vector<int> whichRowFullDelete(); //checks if any row is full and delet all the rows and move everything
                             //downwards
  bool isFull();
  void notify(Subject &whoFrom); //the block is sent to make changes to the entire grid
  std::vector<std::vector<Cell>> getBoard();
  bool getDown() override;
  void setDown();
  Info getInfo();
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

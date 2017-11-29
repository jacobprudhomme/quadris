#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <vector>
#include <cstddef>


class Cell : public Subject<Info, State>, public Observer<Info, State> {
  const int r; //which row is this at
  const int c; //which column is it at
  bool containsBlock; //does it contain a block or not

public:
  Cell(int r, int c, bool b);

  bool isBlock(); // returns true if the cell contains block or not
  //void setPiece(Colour colour);    // Place a piece of given colour here.
  //void toggle();         // Toggles my colour.
  void notify(Subject<Info, State> &whoFrom) override;// My neighbours will call this
                                                // when they've changed state
  Info getInfo() const override;
};
#endif

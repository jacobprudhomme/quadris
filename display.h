#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "info.h"
#include "state.h"

class Display : public Observer<Info, State> {
  std::vector<std::vector<char>> disp;

  const int wDisp = 11;
  const int hDisp = 15;
  const int hScore = 3;

  const std::string level = "Level:";
  const std::string score = "Score:";
  const std::string hiScore = "Hi Score:";

  void moveLeft(int row);
  void moveRight(int row);
  bool nothingBelow(int row, int col);
  void moveDown(int row, int col);
  void cwRotate(int row, int col);
  void ccwRotate(int row, int col);

  public:
    Display();

    void notify(Subject<Info, State> &whoNotified) override;

    friend std::ostream &operator<<(std::ostream &out, const Display &disp);
};

#endif

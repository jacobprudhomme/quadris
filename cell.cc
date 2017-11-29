#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "info.h"

Cell::Cell(int r, int c, bool b): r{r}, c{c}, b{b} {};

bool Cell::isBlock() {
  return containsBlock;
}

//Returns Info
Info Cell::getInfo() const override {
    Info ob;
    ob.row = this->r;
    ob.col = this->c;
    ob.containsBlock = this->b;
    return ob;
}

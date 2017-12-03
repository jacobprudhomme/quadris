#include <iostream>
#include "cell.h"
#include <string>
using namespace std;


Cell::Cell(int r, int c, bool b, int n, int l):
          r{r}, c{c}, containsBlock{b}, numBlock{n}, level{l} {};

void Cell::toggle() {
  containsBlock = !containsBlock;
}

bool Cell::isBlock() {
  return containsBlock;
}

int Cell::getR() {
  return this->r;
}

int Cell::getC() {
  return this->c;
}

/*
string Cell::getStr() {
  return this->block;
}*/

int Cell::getBlockNum() {
  return this->numBlock;
}

//sets the numBlock to be the n i.e
void Cell::setBlockNum(int n) {
  this->numBlock = n;
}


int Cell::getLevel() {
  return this->level;
}

void Cell::setbool(bool x) {
  this->containsBlock = x;
}

void Cell::setLevel(int y) {
  this->level = y;
}

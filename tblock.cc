//
// Created by vyasm on 2017-11-26.
//

#include <algorithm>
#include "tblock.h"

using namespace std;

static void decrement(int &coord) {
  coord--;
}

static void increment(int &coord) {
  coord++;
}

void TBlock::moveLeft() {
  for (int cell = 0; cell < 4; cell++) {

  }

  if (count(xCoord.begin(), xCoord.end(), leftEdge) > 0) {
    for_each(xCoord.begin(), xCoord.end(), &decrement);
  }

  for (int cell = 0; cell < 4; cell++) {

  }
}

void TBlock::moveRight() {
  if (count(xCoord.begin(), xCoord.end(), rightEdge) > 0)
    for_each(xCoord.begin(), xCoord.end(), &increment);
}

void TBlock::moveDown() {
  if (count(yCoord.begin(), yCoord.end(), bottomEdge) > 0)
    if ()
}

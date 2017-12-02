#include "block.h"

using namespace std;

vector<Coord> Block::getPos() { return pos; }

int Block::getLength() { return length; }

int Block::getWidth() { return width; }

void Block::moveLeft()  {
  vector<Coord> temp = getPos();

  bool atLeftEdge = false;

  // Moving left by decrementing x if not already at leftmost edge
  for (Coord n : temp) {
    if (n.x == 0) atLeftEdge = true;
  }
  if (!atLeftEdge) {
    for (Coord &n : temp) {
      (n.x)--;
    }
  }

  pos = temp;
}

void Block::moveRight()  {
  vector<Coord> temp = getPos();

  bool atRightEdge = false;

  // Moving right by incrementing x if not already at rightmost edge
  for (Coord n : temp) {
    if (n.x == 10) atRightEdge = true;
  }
  if (!atRightEdge) {
    for (Coord &n : temp) {
      (n.x)++;
    }
  }

  pos = temp;
}

void Block::moveDown()  {
  vector<Coord> temp = getPos();

  bool atBottomEdge = false;

  // Moving down by incrementing y if not already at bottom
  for (Coord n : temp) {
    if (n.y == 14) atBottomEdge = true;
  }
  if (!atBottomEdge) {
    for (Coord &n : temp) {
      (n.y)++;
    }
  }

  pos = temp;
}

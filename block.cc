#include <iostream>
#include "block.h"
#include <vector>
#include "subject.h"
#include "textdisplay.h"
#include "board.h"
#include "info.h"

using namespace std;

int Block::numblockid = 0;

Block::Block(vector<Coord> pos, int length, int width, Board *b):
  pos{pos}, length{length}, width{width}, id{numblockid++} {
    attach(b);
  }

void Block::init() {
  notifyObservers();
}

vector<Coord> Block::getPos() { return pos; }

int Block::getLength() { return length; }

int Block::getWidth() { return width; }

void Block::setPos(vector<Coord> newPos) { pos = newPos; notifyObservers(); }

void Block::setLength(int newLength) { length = newLength; }

void Block::setWidth(int newWidth) { width = newWidth; }

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

  notifyObservers();
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

  notifyObservers();
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

  notifyObservers();
}

Info Block::getInfo() {
  Info info{};

  info.pos = pos;
  info.id = id;
  info.length = length;
  info.width = width;

  return info;
}

vector<vector<Cell>> Block::getBoard() {
    return vector<vector<Cell>> {};
}

bool Block::getDown() {
    return true;
}

#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "subject.h"

struct Coord {
  int x;
  int y;
};

class Block : public Subject {
  std::vector<Coord> pos;
  int length;
  int width;

  public:
    Block(std::vector<Coord> pos, int length, int width);

    std::vector<Coord> getPos();
    int getLength();
    int getWidth();

    void setPos(std::vector<Coord> newPos);
    void setLength(int newLength);
    void setWidth(int newWidth);

    void moveLeft();
    void moveRight();
    void moveDown();

    virtual void clockwise() = 0;
    virtual void antiClockwise() = 0;
};

#endif

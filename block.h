#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "coord.h"
#include "subject.h"

class Board;
struct Info;
class Cell;

class Block : public Subject {
  std::vector<Coord> pos;
  int length;
  int width;
  static int numblockid;
  int id;
  Board *b = nullptr;

  public:
    Block(std::vector<Coord> pos, int length, int width, Board *b);
    void init();
    
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

    Info getInfo();
    std::vector<std::vector<Cell>> getBoard();
    bool getDown();
};

#endif

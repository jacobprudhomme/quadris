#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>

struct XYCoord {
  int x;
  int y;
};

class Block {
  std::vector<XYCoord> pos;
  int length;
  int width;

  public:
    virtual void clockwise() = 0;
    virtual void antiClockwise() = 0;

    void moveleft();
    void moveright();
    void movedown();

    vector<XYCor> getPos();
    int getLength();
    int getWidth();
};

#endif

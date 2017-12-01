#ifndef TBLOCK_H
#define TBLOCK_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "block.h"

class TBlock : public Block {
  std::vector<int> xCoord{0,1,1,2};
  std::vector<int> yCoord{0,0,1,0};

  const int leftEdge = 0;
  const int rightEdge = 11;
  const int bottomEdge = 15;

  public:
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;

    void clockwise() override;
    void counterClockwise() override;

    std::string prettyprint() override;
};

#endif

#ifndef ZBLOCK_H
#define ZBLOCK_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "block.h"

class ZBlock : public Block {
  std::vector<int> xCoord{0,1,1,2};
  std::vector<int> yCoord{0,0,1,1};

  public:
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;

    void clockwise() override;
    void counterClockwise() override;

    std::string prettyprint() override;
};

#endif

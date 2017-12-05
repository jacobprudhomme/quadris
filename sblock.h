#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class SBlock: public Block {
  int level;

  public:
    SBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

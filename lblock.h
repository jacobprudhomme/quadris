#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class LBlock : public Block {
  int level;

  public:
    LBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

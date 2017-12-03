#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class ZBlock : public Block {
  int level;

  public:
    ZBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class OBlock : public Block {
  int level;

  public:
    OBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

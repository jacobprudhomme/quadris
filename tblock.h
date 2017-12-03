#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class TBlock : public Block {
    int level;

  public:
    TBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

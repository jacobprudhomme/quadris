#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class IBlock : public Block {
  int level;

  public:
    IBlock(TextDisplay *td, Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

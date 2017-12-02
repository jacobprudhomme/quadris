#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block {
  int level;

  public:
    JBlock(TextDisplay *td, Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

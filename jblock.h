#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block {
  int level;

  public:
    JBlock();

    void clockwise() override;
    void antiClockwise() override;
};

#endif

#ifndef SBLOCK
#define SBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>

class SBlock: public Block {
    int level;

public:
    SBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif
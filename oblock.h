#ifndef OBLOCK
#define OBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>

class OBlock : public Block {
    int level;

public:
    OBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

#ifndef TBLOCK
#define TBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>
#include <sstream>

class TBlock: public Block {
    int level;

public:
    TBlock(Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

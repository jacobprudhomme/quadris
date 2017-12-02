#ifndef ZBLOCK
#define ZBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>
#include <sstream>

class ZBlock: public Block {
    int level;

public:
    ZBlock();

    void clockwise() override;
    void antiClockwise() override;
};

#endif

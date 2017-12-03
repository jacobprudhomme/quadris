#ifndef LBLOCK
#define LBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>
#include <sstream>

class LBlock : public Block {
    int level;

public:
    LBlock( Board *b);

    void clockwise() override;
    void antiClockwise() override;
};

#endif

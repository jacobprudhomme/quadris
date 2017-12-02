#ifndef JBLOCK
#define JBLOCK

#include <vector>
#include "block.h"
#include <iostream>
#include <string>
#include <sstream>

class JBlock: public Block {
    int level;

public:
    JBlock();

    void clockwise() override;
    void antiClockwise() override;
};

#endif

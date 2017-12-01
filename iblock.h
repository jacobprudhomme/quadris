#ifndef IBLOCK
#define IBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>

class IBlock: public Blocks {
    int length;
    int width;
    int level;
    vector<vector<char>> piece;
public:
    void clockwise() override;
    void antiClockwise() override;
    std::string prettyprint() override;
    void moveLeftIBlock();
    void moveRightIBlock();
    void moveDownIBlock();
    //std::vector<XYCor> getXYCor() override;
};

#endif

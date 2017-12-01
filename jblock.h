#ifndef JBLOCK
#define JBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>
#include <sstream>

class JBlock: public Blocks {

    int length;
    int width;
    int level;
    vector<vector<char > > piece;
public:
    void clockwise() override;
    void antiClockwise() override;
    std::string prettyprint() override;
    void moveLeftJBlock();
    void moveRighJIBlock();
    void moveDownJBlock();
    //std::vector<XYCor> getXYCor();
};

#endif

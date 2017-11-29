#ifndef ZBLOCK
#define ZBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>
#include <sstream>

class ZBlock: public Blocks {

    int length;
    int width;
    int level;
    vector<vector<char > > piece;
public:
    void clockwise() override;
    void antiClockwise() override;
    string prettyprint() override;

};

#endif

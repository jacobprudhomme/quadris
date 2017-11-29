#ifndef SBLOCK
#define SBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>

class SBlock: public Blocks {

    int length;
    int width;
    int level;
    vector<vector<char > > piece;
public:

    void clockwise() override;
    void antiClockwise() override;
    string prettyprint() override;

    SBlock(int i, int i1, int i2, vector<vector<char> > &vector);
};

#endif

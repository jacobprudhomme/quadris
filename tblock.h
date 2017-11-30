#ifndef TBLOCK
#define TBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>
#include <sstream>

class TBlock: public Blocks {

    int length;
    int width;
    int level;
    vector<vector<char > > piece;
public:
    TBlock(int i, int i1, int i2, vector<vector<char> > &vector);
    void clockwise() override;
    void antiClockwise() override;
    string prettyprint() override;

};

#endif

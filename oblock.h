#ifndef OBLOCK
#define OBLOCK

#include <vector>
#include "blocks.h"
#include <iostream>
#include <string>

class OBlock: public Blocks {

    int length;
     int width;
    int level;
    vector<vector<char> > piece;
public:
    void clockwise() override;
    void antiClockwise() override;
    string prettyprint() override;

};

#endif //UNTITLED12_OBLOCK_H

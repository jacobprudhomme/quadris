#ifndef _BLOCKS_H
#define _BLOCKS_H

#include <string>
#include <iostream>
using namespace std;

class Blocks {

public:
    virtual void clockwise() = 0;
    virtual void antiClockwise() = 0;
    virtual string prettyprint() = 0;

};
#endif //UNTITLED12_BLOCKS_H

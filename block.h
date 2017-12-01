#ifndef _BLOCK_H
#define _BLOCK_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct XYCor{
    int x;
    int y;
};

class Block {
   vector<XYCor>  pos;
    int length;
    int width;
public:
    virtual void clockwise() = 0;
    virtual void antiClockwise() = 0;
    void moveleft();
    void moveright();
    void movedown();
    vector<XYCor>  getpos();
    int getlength();
    int getwidth();

};
#endif

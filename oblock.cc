//
// Created by vyasm on 2017-11-26.
//

#include <sstream>
#include "oblock.h"


void OBlock::antiClockwise() {
}

OBlock::OBlock() : Block(2, 2, vector<XYCor> {XYCor{0,0},XYCor{0,1},XYCor{1,0},XYCor{1,1}}) {}

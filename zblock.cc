//
// Created by vyasm on 2017-11-26.
//
#include <sstream>
#include "sblock.h"
#include "zblock.h"


ZBlock::ZBlock() : Block(2, 3, vector<XYCor> {XYCor{0,0},XYCor{0,1},XYCor{1,1},XYCor{1,2}}) {}

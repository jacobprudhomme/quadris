//
// Created by vyasm on 2017-11-26.
//
#include <sstream>
#include "sblock.h"
#include "jblock.h"



JBlock::JBlock() : Block(2, 3, vector<XYCor> {XYCor{0,0},XYCor{1,0},XYCor{1,1},XYCor{1,2}}) {}

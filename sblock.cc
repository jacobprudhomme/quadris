#include <sstream>
#include "sblock.h"



SBlock::SBlock(int level):Block{2,3,vector<XYCor> {XYCor{0,1},XYCor{0,2},XYCor{1,0},XYCor{1,1}}},level{level}{}
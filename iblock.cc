#include <string>
#include <sstream>
#include "IBlock.h"

using namespace std;

IBlock::IBlock(int level):Block{1,4,vector<XYCor> {XYCor{0,0},XYCor{1,0},XYCor{2,0},XYCor{3,1}}},level{level} {
}

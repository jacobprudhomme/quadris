#include <string>
#include <sstream>
#include <iostream>
#include "IBlock.h"

using namespace std;

void IBlock::clockwise() {
    vector<vector<char> > temp(length*width);
    temp = piece;
    for(int i = 0;i<length;++i) {
        for(int j = 0;j<width;++j) {
          piece[i][j] = temp[j][i];
        }
    }
}

void IBlock::antiClockwise() {
   clockwise();
}

void moveLeftIBlock() {
  this->moveLeft();
}

void moveRightIBlock() {
  this->moveRight();
}

void moveDownIBlock() {
  this->moveDown();
}



string IBlock::prettyprint() {
    ostringstream oss;
    for(int i = 0;i<length;++i){
        for(int j = 0; j<width;++j){
            oss<<piece[i][j];
        }
        oss<<"\n";
    }
    return oss.str();
}

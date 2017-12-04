#include "oblock.h"

#include <vector>
#include "score.h"

using namespace std;

OBlock::OBlock(Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{1,0}, Coord{0,1}, Coord{1,1}}, 2, 2, b},
  level{Score::instance()->getLevel()} {
    //notifyObservers();
  }

void OBlock::clockwise() {
  setPos(getPos());
}

void OBlock::antiClockwise() {
  clockwise();
}
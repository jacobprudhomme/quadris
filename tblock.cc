#include <vector>
#include "tblock.h"
#include "score.h"

using namespace std;

TBlock::TBlock(Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{1,0}, Coord{2,0}, Coord{1,1}}, 2, 3, b},
  level{Score::instance()->getLevel()} {}

void TBlock::clockwise() {
  vector<Coord> temp = getPos();

  bool isThereSpace = true;

  for (Coord n : temp) {
    if (n.x + getLength() > 11) isThereSpace = false;
    if (n.y + getWidth() > 15) isThereSpace = false;
  }

  if (isThereSpace) {
    for (Coord &n : temp) {
      int switchCoord = n.x;
      n.x = -n.y + (getWidth() - 1);
      n.y = switchCoord;
    }

    int length = getLength();
    int width = getWidth();

    setLength(width);
    setWidth(length);
    setPos(temp);
  }
}

void TBlock::antiClockwise() {
  clockwise();
  clockwise();
  clockwise();
}

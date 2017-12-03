#include "sblock.h"

#include <vector>
#include "score.h"

using namespace std;

SBlock::SBlock(Board *b):
  Block{vector<Coord> {Coord{1,0}, Coord{2,0}, Coord{0,1}, Coord{1,1}}, 2, 3, b},
  level{Score::instance()->getLevel()} {
    notifyObservers();
  }

void SBlock::clockwise() {
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

void SBlock::antiClockwise() {
  clockwise();
  clockwise();
  clockwise();
}

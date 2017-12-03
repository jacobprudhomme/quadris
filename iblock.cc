#include "iblock.h"

#include <vector>
#include "score.h"

using namespace std;

IBlock::IBlock(Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{1,0}, Coord{2,0}, Coord{3,0}}, 1, 4, b},
  level{Score::instance()->getLevel()} {
                                       notifyObservers();}

void IBlock::clockwise() {
  vector<Coord> temp = getPos();

  bool isThereSpace = true;

  for (Coord n : temp) {
    if (n.x + getLength() > 11) isThereSpace = false;
    if (n.y + getWidth() > 15) isThereSpace = false;
  }

  if (isThereSpace) {
    for (Coord &n : temp) {
      int switchCoord = n.x;
      n.x = n.y;
      n.y = switchCoord;
    }

    int length = getLength();
    int width = getWidth();

    setLength(width);
    setWidth(length);
    setPos(temp);
  }
}

void IBlock::antiClockwise() {
  clockwise();
}

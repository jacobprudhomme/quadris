#include "jblock.h"

#include <vector>
#include "score.h"

using namespace std;

JBlock::JBlock(TextDisplay *td, Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{0,1}, Coord{1,1}, Coord{2,1}}, 2, 3, td, b},
  level{Score::instance()->getLevel()} {}

void JBlock::clockwise() {
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

void JBlock::antiClockwise() {
  clockwise();
}

#include <sstream>
#include "sblock.h"
#include "score.h"

using namespace std;

SBlock::SBlock(Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{0,1}, Coord{0,2}, Coord{0,3}}, 1, 4, b},
  level{Score::instance()->getLevel()} {}

void SBlock::clockwise() {
    vector<Coord> temp = getPos();

    bool isThereSpace = true;

    for (Coord n : temp) {
        if (n.x + getLength() > 11) isThereSpace = false;
        if (n.y + getWidth() > 15) isThereSpace = false;
    }

    if (isThereSpace) {
        for(int k = 0;k<4;++k){
            temp[k].x = getPos()[k].y;//replace with correct data
            temp[k].y = getWidth()-1-getPos()[k].x;
        }

        int length = getLength();
        int width = getWidth();

        setLength(width);
        setWidth(length);
        setPos(temp);
    }
}

void SBlock::antiClockwise() {
    vector<Coord> temp = getPos();

    bool isThereSpace = true;

    for (Coord n : temp) {
        if (n.x + getLength() > 11) isThereSpace = false;
        if (n.y + getWidth() > 15) isThereSpace = false;
    }

    if (isThereSpace) {
        for(int k = 0;k<4;++k){
            temp[k].x = getLength()- 1 - getPos()[k].y;//replace with correct data
            temp[k].y = getPos()[k].x;
        }

        int length = getLength();
        int width = getWidth();

        setLength(width);
        setWidth(length);
        setPos(temp);
    }
}

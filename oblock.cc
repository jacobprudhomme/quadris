//
// Created by vyasm on 2017-11-26.
//

#include <sstream>
#include "oblock.h"
#include "score.h"

using namespace std;

OBlock::OBlock(TextDisplay *td, Board *b):
  Block{vector<Coord> {Coord{0,0}, Coord{0,1}, Coord{0,2}, Coord{0,3}}, 1, 4, td, b},
  level{Score::instance()->getLevel()} {}

void OBlock::clockwise() {
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

void OBlock::antiClockwise() {
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

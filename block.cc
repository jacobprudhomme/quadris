#include "block.h"

#include <utility>

vector<XYCor>  Block::getpos() {
return pos;
}

int Block::getlength() {
return length;
}

int Block::getwidth() {
    return width;
}

void Block::clockwise(){

    vector<XYCor>  temp;//make a temporary 2d vector

    temp.resize(4);//resize length

        for(int y = 0;y<4;++y){
            XYCor blank = {0,0};
            temp.emplace_back(blank);//fill with empty data
        }


        for(int k = 0;k<4;++k){
            temp[k].x = getpos()[k].y;//replace with correct data
            temp[k].y = width-1-getpos()[k].x;
        }


    getpos() = temp;//reassign

    int temp1 = length;
    this->length = width;     //swap length and width
    this->width = temp1;

    notifyObservers();

}

void Block::moveleft() {

    for(int x1 = 0;x1<4;++x1){
        if(getpos()[x1].x <= 0 ){
            return;
        }
    }

    for(int x2 = 0;x2<=4;++x2){
        --getpos()[x2].x;
    }
    notifyObservers();
}

void Block::moveright() {
    for(int x1 = 0;x1<4;++x1){
        if(getpos()[x1].x >= 10 ){
            return;
        }
    }

    for(int x2 = 0;x2<=4;++x2){
        ++getpos()[x2].x;
    }
    notifyObservers();
}

void Block::movedown() {
    for(int x1 = 0;x1<4;++x1){
        if(getpos()[x1].x >= 14 ){
            return;
        }
    }

    for(int x2 = 0;x2<=4;++x2){
        ++getpos()[x2].y;
    }
    notifyObservers();
}

void Block::antiClockwise() {

    vector<XYCor>  temp;//make a temporary 2d vector

    temp.resize(4);//resize length

    for(int y = 0;y<4;++y){
        XYCor blank = {0,0};
        temp.emplace_back(blank);//fill with empty data
    }


    for(int k = 0;k<4;++k){
        temp[k].x = length - 1 - getpos()[k].y;//replace with correct data
        temp[k].y = getpos()[k].x;
    }


    getpos() = temp;//reassign

    int temp1 = length;
    this->length = width;     //swap length and width
    this->width = temp1;
    notifyObservers();

}

Block::Block(int length, int width, vector<XYCor> pos):length{length},width{width},pos{std::move(pos)} {

}

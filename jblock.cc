//
// Created by vyasm on 2017-11-26.
//
#include <sstream>
#include "sblock.h"
#include "jblock.h"

void JBlock::clockwise() {
    vector<vector<char> > temp;//make a temporary 2d vector

    temp.resize(width);//resize length
    for(int i = 0;i<width;++i){
        temp[i].resize(length);   //resize width
    }

    for(int x = 0;x<width;++x){
        for(int y = 0;y<length;++y){
            temp[x].emplace(temp[x].begin(),' ');//fill with empty data
        }
    }

    for(int j = 0;j<width;++j){
        for(int k = 0;k<length;++k){
            temp[j][k] = piece[length-1-k][j];//replace with correct data
        }
    }

    piece = temp;//reassign

    int temp1 = length;
    this->length = width;     //swap length and width
    this->width = temp1;

}

void JBlock::antiClockwise() {
    vector<vector<char> > temp;//make a temporary 2d vector

    temp.resize(width);//resize length
    for(int i = 0;i<width;++i){
        temp[i].resize(length);   //resize width
    }

    for(int x = 0;x<width;++x){
        for(int y = 0;y<length;++y){
            temp[x].emplace(temp[x].begin(),' ');//fill with empty data
        }
    }

    for(int j = 0;j<width;++j){
        for(int k = 0;k<length;++k){
            temp[j][k] = piece[k][width-1-j];//replace with correct data
        }
    }

    piece = temp;//reassign

    int temp1 = length;
    this->length = width;     //swap length and width
    this->width = temp1;


}

string JBlock::prettyprint() {
    ostringstream oss;
    for(int i = 0;i<length;++i){
        for(int j = 0; j<width;++j){
            oss<<piece[i][j];
        }
        oss<<"\n";
    }
    return oss.str();
}

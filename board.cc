#include <iostream>
#include <vector>
#include <cstddef>

#include "cell.h"

using namespace std;

Board::~Board () {
  delete td;
}

void Board::setObserver(Observer* ob) {
    this->ob = ob;
}

void Board::init(int rows, int columns) {
  theBoard.clear();
  td = nullptr;
  this->rows = rows;
  this->cols = columns;
  this->numBlock = 0;
  //Initilize the board with default cells
  //Rows: 18 (3 reserved for rotation)
  //columns: 11
  for(int i = 0; i < rows; ++i) {
    vector <Cell> c;
    for(int j = 0; j < columns; j++) {
      Cell temp{i, j, false, "N", 0, -1};
      c.emplace_back(temp);
    }
    theBoard.emplace_back(c);
  }

  //Text display to print that out
  //td = &display{rows, columns};
}

//Given vector of the blocks position's
//there should be another thing for which type of block it is
void Board::notify(Subject &whoFrom) {
  //if already full then remove those rows
  Board::whichRowFullDelete();

  int x = this->numBlock++;
  int size = whoFrom.size();
  int counter = 0;
  for(int i = 3; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if (counter == size - 1) return;
      if((whoFrom[counter].getpos().x == i) && (whoFrom[counter].getpos().y == j)) {
        theBoard[i][j].toggle();
        theBoard[i][j].setBlockNum(x);
        counter++;
      }
    }
  }
}


//Vector which tells which row is fille
void Board::whichRowFullDelete() {
  //we have to make sure it start form rows: 3
  //As first three rows are reserved
  for(int i = 3; i < rows; ++i) {
    int counter = 0;
    for(int j = 0; j < cols; ++j) {
      if(theBoard[i][j].isBlock() == true) {
        counter++;
      } else {
        break;
      }
    }
    if (counter == cols) {
      //v.emplace_back(i);
      //we know i should be removed
      for(int x = i; x > 3; --x) {
        for(int j = 0; j < cols; ++j) {
          theBoard[x][j].setbool(theBoard[x-1][j].isBlock());
          theBoard[x][j].setBlockNum(theBoard[x-1][j].getBlockNum());
          //we need to set string too but we dont have right now
        }
      }
      //setting the first row
      for(int j = 0; j < cols; ++j){
        theBoard[3][j].setbool(false);
        theBoard[3][j].setBlockNum(0);
        // level and string for which type of block it it
      }
    }
  }
}

//Checking the to right cornor to see if there can be more blocks
//or not
bool Board::isFull() {
  for(int i = 3; i < 6; ++i) {
    for(int j = 0; j < 4; ++j) {
      if(theBoard[i][j].isBlock()) {
        return true;
      }
    }
  }
  return false;
}


ostream& operator<<(ostream &out, const Board &b) {
    out << *(b.td);
    return out;
}

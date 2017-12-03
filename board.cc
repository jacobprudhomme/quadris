#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "board.h"

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
      Cell temp{i, j, false, 0, -1};
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
  Board::whichRowFullDelete(); //calculates the full score, if we wont to
  //int x = this->numBlock++;
  //already on the table then we need to find and mutate the table
  int counter = 0;
  int x = whoFrom.numblockid();
  int lev = whoFrom.level();
  int size = 4; //four vectors always
  bool runThat = true;

  //make sure it if doesn't intersect and is not below the down line
  for(int i = 3; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if (counter == size - 1) runThat = false;
      if (runThat) {
        if (((theBoard[i][j].getR() == whoFrom.getpos()[counter].x) &&
            (theBoard[i][j].getC() == whoFrom.getpos()[counter].y)) ||
            (whoFrom.getpos()[counter].x < 0) ||
            (whoFrom.getpos()[counter].x > 11) ||
            (whoFrom.getpos()[counter].y < 0) ||
            (whoFrom.getpos()[counter].y > 18))  {
              return;
            }
            counter++;
      }
    }
  }
  runThat = true;
  for(int i = 3; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if (counter == size - 1) runThat = false;
      if (runThat) {
        if(x == theBoard[i][j].getBlockNum()) {
          theBoard[i][j].toggle(); //switching the bool to false
          theBoard[i][j].setBlockNum(0); //we set the bool to initial val
          theBoard[i][j].setLevel(-1); //initial level i.e -1
          counter++;
        }
      }
    }
  }
  for(int i = 3; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if (counter == size - 1) return;
      if ((whoFrom.getPos()[counter].x == i) && ((whoFrom.getpos()[counter].y + 3) == j)) {
        theBoard[i][j].toggle();
        theBoard[i][j].setBlockNum(x);
        theBoard[i][j].setLevel(lev);
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
          theBoard[x][j].setLevel(theBoard[x-1][j].getLevel());
          //we need to set string too but we dont have right now
        }
      }
      //setting the first row
      for(int j = 0; j < cols; ++j) {
        theBoard[3][j].setbool(false);
        theBoard[3][j].setBlockNum(0);
        theBoard[3][j].setLevel(-1);
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

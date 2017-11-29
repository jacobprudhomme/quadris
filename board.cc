#include <iostream>
#include <vector>
#include <cstddef>


Board::~Board () {
  delete td;
}

void Board::init(int rows, int columns) {
  theBoard.clear();
  td = nullptr;

  //Displaying the LEVEL, SCORE AND HI SCORE


  //Initilize the board with default cells
  //Rows: 18 (3 reserved for rotation)
  //columns: 11
  for(int i = 0; i < rows; ++i) {
    vector <Cell> c;
    for(int j = 0; j < columns; j++) {
        c.emplace_back(Cell(i, j, false));
    }
    theBoard.emplace_back(c);
  }

  td = &display{rows, columns};

  //have to check if there isn't any line which is
  //full of blocks if it is remove it

  //.............


  //Attaching observers
  for(int i = 3; i < rows; ++i) {
    for(int j = 0; j < columns; ++j) {
      //Case for top left edge
      if(i == 3 && j == 0) {
        theBoard[i][j].attach(&theBoard[i][j+1]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
        theBoard[i][j].attach(&theBoard[i+1][j+1]);
      }

      //Case for the first coloumn
      if(j == 0 && i != 3 && i != rows - 1) {
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i-1][j+1]);
        theBoard[i][j].attach(&theBoard[i][j+1]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
        theBoard[i][j].attach(&theBoard[i+1][j+1]);
      }

      //Case for the bottom left edge
      if(i == rows - 1 && j == 0) {
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i-1][j+1]);
        theBoard[i][j].attach(&theBoard[i][j+1]);
      }

      //case for bottom  row
      if(i == rows - 1 && j != 0 && j != coloumns - 1) {
        theBoard[i][j].attach(&theBoard[i][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i-1][j+1]);
        theBoard[i][j].attach(&theBoard[i][j+1]);
      }

      //Case for bottom right edge
      if(i == rows - 1 && j != 0 && j == coloumns - 1) {
        theBoard[i][j].attach(&theBoard[i-1][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i][j-1]);
      }

      //Case for last coloumn
      if(i != 3 && i != rows - 1 && j == columns - 1) {
        theBoard[i][j].attach(&theBoard[i][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
        theBoard[i][j].attach(&theBoard[i+1][j-1]);
      }

      //Case for top right edge
      if(i == 3 && j == coloumns - 1) {
        theBoard[i][j].attach(&theBoard[i][j-1]);
        theBoard[i][j].attach(&theBoard[i+1][j-1]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
      }

      //Case for First row i.e 3rd
      if(i == 3 && j != 0 && j != coloumns - 1) {
        theBoard[i][j].attach(&theBoard[i][j-1]);
        theBoard[i][j].attach(&theBoard[i][j+1]);
        theBoard[i][j].attach(&theBoard[i+1][j-1]);
        theBoard[i][j].attach(&theBoard[i+1][j+1]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
      }

      //All the others cells i.e in center surrounded by 8 other cells
      else {
        theBoard[i][j].attach(&theBoard[i][j-1]);
        theBoard[i][j].attach(&theBoard[i][j+1]);
        theBoard[i][j].attach(&theBoard[i-1][j]);
        theBoard[i][j].attach(&theBoard[i+1][j]);
        theBoard[i][j].attach(&theBoard[i-1][j-1]);
        theBoard[i][j].attach(&theBoard[i-1][j+1]);
        theBoard[i][j].attach(&theBoard[i+1][j-1]);
        theBoard[i][j].attach(&theBoard[i+1][j+1]);
      }
    }
  }
}

//Vector which tells which row is filled
std::vector<int> Board::whichRowFull() {
  //we have to make sure it start form rows: 3
  //As first three rows are reserved
  std::vector<int> v;
  for(int i = 0; i < rows; ++i) {
    int counter = 0;
    for(int j = 0; j < columns; ++j) {
      if(theBoard[i][j].isBlock() == true) {
        counter++;
      } else {
        break;
      }
    }
    if (counter == columns) {
      v.emplace_back(i);
    }
  }
  return v;
}

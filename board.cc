#include <iostream>
#include <algorithm>

#include "board.h"
#include "cell.h"
#include "score.h"
#include "gameover.h"

using namespace std;

Board::~Board () {
  delete td;
}

Board::Board(int r, int c, int n): rows{r}, cols{c}, numBlock{n} {}

void Board::setObserver(Observer* ob) {
  this->ob = ob;
}

void Board::init() {
  // Clear all the old stuff
  Score::instance()->setScore(0);
  Score::instance()->setLevel(0);
  theBoard.clear();
  detach();
  delete td;

  //Initilize the board with default cells
  //Rows: 18 (3 reserved for rotation)
  //columns: 11
  for (int i = 0; i < rows; ++i) {
    vector<Cell> c;
    for (int j = 0; j < cols; j++) {
      Cell temp{i, j, false, -1, 0};
      c.emplace_back(temp);
    }
    theBoard.emplace_back(c);
  }

  //Text display to print that out
  td = new TextDisplay{};
  attach(td);
}

struct xy {
  int id;
  int lvl;
};

static bool compIds(xy xy1, xy xy2) {
  return xy1.id < xy2.id;
}

static int sqr(int x) {
  return x * x;
}

void Board::calculatingScore(vector<int> v) {
  vector<xy> xys;
  for (int i : v) {
    for (Cell cell : theBoard.at(i)) {
      xys.emplace_back(xy{cell.getBlockNum(), cell.getLevel()});
    }
  }

  sort(xys.begin(), xys.end(), &compIds);
  int counter = 0;
  int score = 0;
  if(xys.size() > 0) {
    for (unsigned int i = 0; i < xys.size() - 1 ; ++i) {
      if(xys.at(i).id == xys.at(i+1).id){
        counter++;
      } else {
        counter = 0;
      }
      if (counter == 3){
        counter = 0;
        score += sqr(xys.at(i).lvl + 1);
      }
    }
  }
  score += v.size()*sqr(Score::instance()->getLevel()+1);

  Score::instance()->setScore(Score::instance()->getScore() + score);
  if (Score::instance()->getScore() > Score::instance()->getHiScore()) {
    Score::instance()->setHiScore(Score::instance()->getScore());
  }
}

void Board::deleteRows(vector<int> v) {
  for (int i : v) {
    for(int x = i; x > 3; --x) {
      for(int j = 0; j < cols; ++j) {
        theBoard.at(x).at(j).setbool(theBoard.at(x-1).at(j).isBlock());
        theBoard.at(x).at(j).setBlockNum(theBoard.at(x-1).at(j).getBlockNum());
        theBoard.at(x).at(j).setLevel(theBoard.at(x-1).at(j).getLevel());
        //we need to set string too but we dont have right now
      }
    }
    //setting the first row
    for(int j = 0; j < cols; ++j) {
      theBoard.at(3).at(j).setbool(false);
      theBoard.at(3).at(j).setBlockNum(-1);
      theBoard.at(3).at(j).setLevel(0);
      // level and string for which type of block it it
    }
  }
}


//Given vector of the blocks position's
//there should be another thing for which type of block it is
void Board::notify(Subject &whoFrom) {
  if (isFull()) {
    throw GameOver{};
  }

  // Check if out of bounds or there is a block in the way; then exit function if so
  for (Coord &xy : whoFrom.getInfo().pos) {
    if ((xy.x < 0) || (xy.x > 10)) return;
    if ((xy.y < 0) || (xy.y > 17)) return;
    if (theBoard.at(xy.y + 3).at(xy.x).isBlock()) return;
  }

  // Clears all the old cells for the block
  for (auto &row : theBoard) {
    for (Cell &cell : row) {
      if (cell.getBlockNum() == whoFrom.getInfo().id) {
        cell.setbool(false);
        cell.setBlockNum(-1);
        cell.setLevel(0);
      }
    }
  }

  // Set new cells for the moved block
  for (Coord &xy : whoFrom.getInfo().pos) {
    theBoard.at(xy.y + 3).at(xy.x).setbool(true);
    theBoard.at(xy.y + 3).at(xy.x).setBlockNum(whoFrom.getInfo().id);
    theBoard.at(xy.y + 3).at(xy.x).setLevel(whoFrom.getInfo().level);
  }

  // Effect the changes on the board/textdisplay
  vector<int> vec = whichRowFullDelete();
  calculatingScore(vec);
  deleteRows(vec);

  notifyObservers();
}


//Vector which tells which row is fille
vector<int> Board::whichRowFullDelete() {
  //we have to make sure it start form rows: 3
  //As first three rows are reserved
  vector<int> v;
  for(int i = 3; i < rows; ++i) {
    int counter = 0;
    for(int j = 0; j < cols; ++j) {
      if(theBoard.at(i).at(j).isBlock() == true) {
        counter++;
      } else {
        break;
      }
    }
    if (counter == cols) {
      v.emplace_back(i);
      //we know i should be removed
    }
  }
  return v;
}


//Checking the to right cornor to see if there can be more blocks
//or not
bool Board::isFull() {
  for (int x = 0; x < 11; x++) {
    bool isFull = true;

    for (int y = 3; y < 18; y++) {
      isFull = isFull && theBoard.at(y).at(x).isBlock();
    }

    if (isFull) return true;
  }

  return false;
}

vector<vector<Cell>> Board::getBoard() {
  return theBoard;
}

ostream& operator<<(ostream &out, const Board &b) {
  out << *b.td;
  return out;
}

Info Board::getInfo() {
  return Info{};
}

void Board::setDown() {
  this->down = false;
}

bool Board::getDown() {
  return this->down;
}

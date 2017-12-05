#include <iostream>
#include "board.h"
#include "cell.h"
#include <cstddef>
#include "score.h"
#include <algorithm>

using namespace std;

Board::~Board () {
  delete td;
}

Board::Board(int r, int c, int n): rows{r}, cols{c}, numBlock{n} {};

void Board::setObserver(Observer* ob) {
    this->ob = ob;
}

void Board::init() {
    Score::instance()->setScore(0);
    Score::instance()->setLevel(0);
    theBoard.clear();
    detach();
    delete td;
  //Initilize the board with default cells
  //Rows: 18 (3 reserved for rotation)
  //columns: 11
  for(int i = 0; i < rows; ++i) {
    vector<Cell> c;
    for(int j = 0; j < cols; j++) {
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
      if(xys[i].id == xys[i+1].id){
        counter++;
      } else {
        counter = 0;
      }
      if (counter == 3){
        counter = 0;
        score += sqr(xys[i].lvl + 1);
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
        theBoard[x][j].setbool(theBoard[x-1][j].isBlock());
        theBoard[x][j].setBlockNum(theBoard[x-1][j].getBlockNum());
        theBoard[x][j].setLevel(theBoard[x-1][j].getLevel());
        //we need to set string too but we dont have right now
      }
    }
    //setting the first row
    for(int j = 0; j < cols; ++j) {
      theBoard[3][j].setbool(false);
      theBoard[3][j].setBlockNum(-1);
      theBoard[3][j].setLevel(0);
      // level and string for which type of block it it
    }
  }
}


//Given vector of the blocks position's
//there should be another thing for which type of block it is
void Board::notify(Subject &whoFrom) {
  //if already full then remove those rows
 //calculates the full score, if we wont to

  int counter = 0;
  int x = whoFrom.getInfo().id;
  int lev = whoFrom.getInfo().level;
  int size = 4;
  bool runThat = true;
  down = true;
  //make sure it if doesn't intersect and is not below the down line

  for (int i = 3; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (counter > size - 1) runThat = false;
      if (runThat) {
        if (((theBoard[i][j].getC() == whoFrom.getInfo().pos[counter].x) &&
             (theBoard[i][j].getR() == whoFrom.getInfo().pos[counter].y + 3) &&
	           (theBoard[i][j].isBlock())) ||
            (whoFrom.getInfo().pos[counter].x < 0) ||
            (whoFrom.getInfo().pos[counter].x > 10) ||
            (whoFrom.getInfo().pos[counter].y + 3 < 0) ||
            (whoFrom.getInfo().pos[counter].y + 3 > 17))  {
              counter++;
              down = false;
              return;
            }
      }
    }
  }
  counter = 0;
  runThat = true;
  size = 4;
  for (int i = 3; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (counter > size - 1) runThat = false;
      if (runThat) {
        int y = theBoard[i][j].getBlockNum();
        if (x == y) {
          theBoard[i][j].setbool(false); //switching the bool to false
          theBoard[i][j].setBlockNum(-1); //we set the bool to initial val
          theBoard[i][j].setLevel(0); //initial level i.e -1
          counter++;
        }
      }
    }
  }

  for (auto &n : whoFrom.getInfo().pos) {
      theBoard[n.y + 3][n.x].toggle();
      theBoard[n.y + 3][n.x].setBlockNum(x);
      theBoard[n.y + 3][n.x].setLevel(lev);
  }
  vector<int> whichRowsFull = whichRowFullDelete();
  calculatingScore(whichRowsFull);
  deleteRows(whichRowsFull);
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
      if(theBoard[i][j].isBlock() == true) {
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
  for(int i = 3; i < 6; ++i) {
    for(int j = 0; j < 4; ++j) {
      if(theBoard[i][j].isBlock()) {
        return true;
      }
    }
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

#include "textdisplay.h"
#include "score.h"
#include "upcoming.h"
#include "block.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay():
  gridDisp{vector<vector<char>> {}} {
    for (int row = 0; row < 18; row++) {
      gridDisp.emplace_back(vector<char> {});

      for (int cell = 0; cell < 11; cell++) {
        gridDisp.at(row).emplace_back(' ');
      }
    }

    track = -1;
  }

void TextDisplay::notify(Subject &whoFrom) {
  vector<vector<Cell>> theBoard = whoFrom.getBoard();

  if(whoFrom.getDown() == false){
    ++track;
  }
  for (auto &row : gridDisp) {
    for (char &cell : row) {
      cell = ' ';
    }
  }

  for (auto &row : theBoard) {
    for (auto &cell : row) {
      if (cell.isBlock()) gridDisp.at(cell.getR()).at(cell.getC()) = '#';
    }
  }
}

ostream &operator<<(ostream &out, TextDisplay &td) {
  // Print out Score section
  out << "Score: " << Score::instance()->getScore() << endl;
  out << "Hi-Score: " << Score::instance()->getHiScore() << endl;
  out << "Level: " << Score::instance()->getLevel() << endl;
  out << "-----------" << endl;

  // Print out Grid section
  for (auto row : td.getgrid()) {
    for (char cell : row) {
      out << cell;
    }
    out << endl;
  }

  // Print out NextBlock section
  out << "-----------" << endl;
  if (td.getTrack() == -1){
    td.setTrack(0);
  }
  unsigned int count = td.getTrack() + 1;
  if (count<= Upcoming::instance()->getNextBlocks().size()) {
    out << "Next:" << endl;
    char nextblock = Upcoming::instance()->getNextBlocks().at(td.getTrack()+1);

    if (nextblock == 'I') {
      out << "IIII" << endl;
    } else if (nextblock == 'J') {
    	out <<'J' << '\n' << "JJJ";
    } else if (nextblock == 'L') {
      out << "  L" << endl << "LLL";
    } else if (nextblock == 'O') {
      out << "OO" << endl << "OO";
    } else if(nextblock == 'T') {
    	out << "TTT" << '\n' << " T";
    } else if (nextblock == 'S') {
      out << " SS" << endl << "SS ";
    }else if (nextblock == 'Z') {
    	out << "ZZ" << '\n' << " ZZ";
    }
  }

  return out;
}

int TextDisplay::getTrack() {
  return track;
}

bool TextDisplay::getcurrPos() {
  return currPos;
}

void TextDisplay::setTrack(int n) {
  track = n;
}

void TextDisplay::setcurrPos(bool x) {
  currPos= x;
}

vector<vector<char>> TextDisplay::getgrid() {
  return gridDisp;
}

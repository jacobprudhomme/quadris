#include "textdisplay.h"
#include "score.h"
#include "upcoming.h"

using namespace std;

TextDisplay::TextDisplay():
  gridDisp{vector<vector<char>> {}} {
    for (int row = 0; row < 15; row++) {
      gridDisp.emplace_back(vector<char> {});

      for (int cell = 0; cell < 11; cell++) {
        gridDisp.at(row).emplace_back(' ');
      }
    }
  }

void TextDisplay::notify(Subject &whoFrom) {
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  out << "Score: " << Score::instance()->getScore() << endl;
  out << "Hi-Score: " << Score::instance()->getHiScore() << endl;
  out << "Level: " << Score::instance()->getLevel() << endl;
  out << "-----------" << endl;

  for (auto row : td.gridDisp) {
    for (char cell : row) {
      out << cell;
    }
    out << endl;
  }

  out << "-----------" << endl;
  out << Upcoming::instance()->getNextBlocks().at(0) << endl;
  out << Upcoming::instance()->getNextBlocks().at(1) << endl;
  out << Upcoming::instance()->getNextBlocks().at(2) << endl;

  return out;
}

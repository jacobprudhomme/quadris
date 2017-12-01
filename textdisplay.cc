#include "textdisplay.h"
#include "score.h"

using namespace std;

TextDisplay::TextDisplay():
  scoreDisp{vector<string> (4)},
  gridDisp{vector<vector<char>> {}},
  upcomingDisp{vector<string> (4)} {
    scoreDisp.at(0) = "Score: " + to_string(Score::instance()->getScore());
    scoreDisp.at(1) = "Hi-Score: " + to_string(Score::instance()->getHiScore());
    scoreDisp.at(2) = "Level: " + to_string(Score::instance()->getLevel());
    scoreDisp.at(3) = "-----------";

    for (int row = 0; row < 15; row++) {
      gridDisp.emplace_back(vector<char> {});

      for (int cell = 0; cell < 11; cell++) {
        gridDisp.at(row).emplace_back(' ');
      }
    }

    upcomingDisp.at(0) = "-----------";
    upcomingDisp.at(1) = "I";
    upcomingDisp.at(2) = "J";
    upcomingDisp.at(3) = "Z";
  }

void TextDisplay::notify(Subject &whoFrom) {

}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (string line : td.scoreDisp) {
    out << line << endl;
  }

  for (auto row : td.gridDisp) {
    for (char cell : row) {
      out << cell;
    }
    out << endl;
  }

  for (string line : td.upcomingDisp) {
    out << line << endl;
  }

  return out;
}

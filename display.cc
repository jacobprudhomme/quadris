#include "display.h"

using namespace std;

void Display::moveLeft(int row) {
  const int blockHeight = row + 3;

  for (int y = row; y < blockHeight; y++) {
    for (int x = 1; x < wDisp; x++) {
      disp.at(y).at(x - 1) = disp.at(y).at(x);
    }
    disp.at(y).at(wDisp - 1) = ' ';
  }
}

void Display::moveRight(int row) {
  const int blockHeight = row + 3;

  for (int y = row; y < blockHeight; y++) {
    for (int x = 0; x < (wDisp - 1); x++) {
      disp.at(y).at(x + 1) = disp.at(y).at(x);
    }
    disp.at(y).at(0) = ' ';
  }
}

bool Display::nothingBelow(int row, int col) {
  const int blockWidth = col + 3;
  const int blockHeight = row + 3;

  if (blockHeight >= hDisp) return false;

  for (int x = col; x < blockWidth; x++) {
    if (disp.at(blockHeight).at(x) != ' ') return false;
  }

  return true;
}

void Display::moveDown(int row, int col) {
  const int blockWidth = col + 3;
  const int blockHeight = row + 3;

  for (int y = blockHeight - 1; y >= row; y--) {
    for (int x = col; x < blockWidth; x++) {
      disp.at(y + 1).at(x) = disp.at(y).at(x);
    }
  }
  for (int x = col; x < blockWidth; x++) {
    disp.at(row).at(x) = ' ';
  }
}

void Display::cwRotate(int row, int col) {
  const int blockWidth = col + 3;
  const int blockHeight = row + 3;

  vector<vector<char>> tmp{};
  for (int i = 0; i < 3; i++) {
    tmp.emplace_back(vector<char> {});
  }
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      tmp.at(j).emplace_back(disp.at(row + (2 - i)).at(col + j));
    }
  }

  for (int y = row; y < blockHeight; y++) {
    for (int x = col; x < blockWidth; x++) {
      disp.at(y).at(x) = tmp.at(y - row).at(x - col);
    }
  }
}

void Display::ccwRotate(int row, int col) {
  const int blockWidth = col + 3;
  const int blockHeight = col + 3;

  vector<vector<char>> tmp{};
  for (int i = 0; i < 3; i++) {
    tmp.emplace_back(vector<char> {});
  }
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      tmp.at(j).emplace_back(disp.at(row + (2 - i)).at(col + (2 - j)));
    }
  }

  for (int y = row; y < blockHeight; y++) {
    for (int x = col; x < blockWidth; x++) {
      disp.at(y).at(x) = tmp.at(y - row).at(x - col);
    }
  }
}

Display::Display(): disp{vector<vector<char>> {}} {
  for (int row = 0; row < hScore; row++) {
    disp.emplace_back(vector<char> {});
  }
  disp.at(0) = vector<char> {level.begin(), level.end()};
  disp.at(1) = vector<char> {score.begin(), score.end()};
  disp.at(2) = vector<char> {hiScore.begin(), hiScore.end()};
  for (int row = 0; row < hScore; row++) {
    for (int cell = disp.at(row).size(); cell < wDisp; cell++) {
      disp.at(row).emplace_back(' ');
    }
  }

  for (int row = 3; row < hDisp; row++) {
    disp.emplace_back(vector<char> {});

    for (int cell = 0; cell < wDisp; cell++) {
      disp.at(row).emplace_back('-');
    }
  }
}

void Display::notify(Subject<Info, State> &whoNotified) {
  Info info = whoNotified.getInfo();
  State state = whoNotified.getState();

  int row = info.row;
  int col = info.col;

  Move move = state.move;

  if (move == Move::Left) {
    if (col > 0) moveLeft(row);
  } else if (move == Move::Right) {
    if (col < wDisp) moveRight(row);
  } else if (move == Move::Down) {
    if (nothingBelow(row, col)) moveDown(row, col);
  } else if (move == Move::CWRotate) {
    cwRotate(row, col);
  } else if (move == Move::CCWRotate) {
    ccwRotate(row, col);
  }
}

ostream &operator<<(ostream &out, const Display &disp) {
  for (auto row : disp.disp) {
    for (auto cell : row) {
      out << cell;
    }
    out << endl;
  }

  return out;
}

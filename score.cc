#include "score.h"

Score::Score(): score{0}, hiScore{0}, level{0} {}

int Score::getScore() { return score; }
int Score::getHiScore() { return hiScore; }
int Score::getLevel() { return level; }

void Score::setScore(int pts) { score = pts; }
void Score::setHiScore(int pts) { hiScore = pts; }
void Score::setLevel(int lvl) { level = lvl; }

Score *Score::instance() {
  if (!singleton_instance) singleton_instance = new Score{};
  return singleton_instance;
}

#include "upcoming.h"

using namespace std;

Upcoming::Upcoming(): upcoming{vector<char> (3)} {}

vector<char> Upcoming::getNextBlocks() { return upcoming; }

void Upcoming::setNextBlocks(char toAdd) {
  upcoming.at(0) = upcoming.at(1);
  upcoming.at(1) = upcoming.at(2);
  upcoming.at(2) = toAdd;
}

Upcoming *Upcoming::instance() {
  if (!singleton_instance) singleton_instance = new Upcoming{};
  return singleton_instance;
}

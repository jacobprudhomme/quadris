#include "subject.h"

void Subject::attach(Observer *ob) {
  obs.emplace_back(ob);
}

void Subject::notifyObservers() {
  for (auto &ob : obs) ob->notify(*this);
}

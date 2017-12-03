#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"
#include "block.h"

class Observer;

class Subject {
  std::vector<Observer *> obs;

  public:
    void attach(Observer *ob);
    void notifyObservers();

    virtual std::vector<Coord> getPos() = 0;
};

#endif

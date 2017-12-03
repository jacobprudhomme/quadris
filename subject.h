#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"
#include "block.h"
#include "info.h"

class Observer;

class Subject {
  std::vector<Observer *> obs;

  public:
    void attach(Observer *ob);
    void notifyObservers();

    virtual Info getInfo() = 0;
};

#endif

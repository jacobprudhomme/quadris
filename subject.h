#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Observer;

class Subject {
  std::vector<Observer *> obs;

  public:
    void attach(Observer *ob);
    void notifyObservers();
};

#endif

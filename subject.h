#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "info.h"
#include "observer.h"


class Observer;
class Cell;
struct Info;

class Subject {
  std::vector<Observer *> obs;

  public:
    void attach(Observer *ob);
    void detach();
    void notifyObservers();

    virtual Info getInfo() = 0;
    virtual std::vector<std::vector<Cell>> getBoard() = 0;
    virtual bool getDown() = 0;
};

#endif

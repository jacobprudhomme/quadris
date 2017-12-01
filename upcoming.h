#ifndef UPCOMING_H
#define UPCOMING_H

#include <vector>

class Upcoming {
  std::vector<char> upcoming;

  static Upcoming *singleton_instance;

  Upcoming();

  public:
    std::vector<char> getNextBlocks();

    void setNextBlocks(char toAdd);

    static Upcoming *instance();
};

#endif

#ifndef INFO_H
#define INFO_H

#include <vector>
#include "block.h"

struct Info {
  std::vector<Coord> pos;
  int id;
  int length;
  int width;
};

#endif

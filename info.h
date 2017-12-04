#ifndef INFO_H
#define INFO_H

#include <vector>

struct Coord;

struct Info {
  std::vector<Coord> pos;
  int id;
  int length;
  int width;
  int level;
};

#endif

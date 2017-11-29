#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "state.h"

struct Info {
  int row, col;
  bool containsBlock; //does it contain a block or not
  //Colour colour;
};

#endif

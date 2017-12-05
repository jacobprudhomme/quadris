#ifndef UPCOMING_H
#define UPCOMING_H

#include <vector>
#include "block.h"

class Upcoming {
  std::vector<char> upcoming;
  std::vector<char> upcoming2;
  std::vector<Block *> b;
  static Upcoming *singleton_instance;
  int level;

  public:
    std::vector<char> getNextBlocks();
    std::vector<char> getVec();
    std::vector<Block *> getVecBlock();
    int getlevel();
    Block *getPosBlock(int x);
    int sizeT();

    void setVec(std::vector<char> v, std::vector<Block *> b, int l);
    void setlevel(int level);
    void updatenextblock(int level, double seed, bool isseed, Board *obj);

    static Upcoming *instance();
};

#endif

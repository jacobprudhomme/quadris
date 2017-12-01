#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>

class Block {
  public:
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;

    virtual void clockwise() = 0;
    virtual void counterClockwise() = 0;

    virtual std::string prettyprint() = 0;

    virtual ~Block() = default;
};

#endif

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "observer.h"

class TextDisplay : public Observer {
  std::vector<std::string> scoreDisp;
  std::vector<std::vector<char>> gridDisp;
  std::vector<std::string> upcomingDisp;

  public:
    TextDisplay();

    void notify(Subject &whoFrom) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

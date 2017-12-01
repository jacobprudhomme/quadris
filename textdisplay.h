#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <string>
#include "observer.h"

class TextDisplay : public Observer {
  std::vector<std::string> scoreDisp;
  std::vector<std::vector<char>> gridDisp;
  std::vector<char> upcomingDisp;

  public:
    void notify(Subject &whoFrom) override;
};

#endif

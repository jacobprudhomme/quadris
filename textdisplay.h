#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"

class TextDisplay : public Observer {
  std::vector<std::vector<char>> theDisplay;

  public:
    void notify(Subject &whoFrom) override;
};

#endif

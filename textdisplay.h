#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "observer.h"

using namespace std;

class TextDisplay : public Observer {
  std::vector<std::vector<char>> gridDisp;
  int track;
  bool currPos;
  
  public:
    TextDisplay();

    void notify(Subject &whoFrom) override;
    int getTrack();
    bool getcurrPos();
  	void setTrack(int n);
  	void setcurrPos(bool x);
	std::vector<std::vector<char> > getgrid();
    friend std::ostream &operator<<(std::ostream &out,  TextDisplay &td);
};

#endif


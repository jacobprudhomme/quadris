#ifndef BLOCKSELECTOR
#define BLOCKSELECTOR
#include <iostream>
#include <vector>
#include <string>
#include "upcoming.h"

using namespace std;

class Blockselector {
    string file0;
    string file3;
    int level;
    
    public:
    int getlevel();
    string getfil0();
    string getfile3();
    void runlevel();
    
}
#endif

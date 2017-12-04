#include "blockselector.h"
#include "block.h"
#include <sstream>
#include <fstream>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"

using namespace std;

int Blockselector::getlevel(){
    return level;
}

string Blockselector::getfile0(){
    return file0;
}


Blockselector::Blockselector(string f1, int x): file0{f1}, level{x} {}


void Blockselector::runlevel(Board *obj) {
    if(getlevel() == 0){
        ifstream f(getfile0());
        char s;
        vector<Block *> allblocks;
        vector<char> allchars;
        while(f >> s){
        
            if(s == 'I') {
                Block *i = new IBlock(obj);
                allblocks.emplace_back(i);
                allchars.emplace_back(s);
            } else if (s == 'J') {
                Block *j = new JBlock(obj);
                allblocks.emplace_back(j);
                allchars.emplace_back(s);
            } else if (s == 'L') {
                Block *l = new LBlock(obj);
                allblocks.emplace_back(l);
                allchars.emplace_back(s);
            } else if (s == 'O') {
                Block *o = new OBlock(obj);
                allblocks.emplace_back(o);
                allchars.emplace_back(s);
            } else if (s == 'S') {
                Block *ss = new SBlock(obj);
                allblocks.emplace_back(ss);
                allchars.emplace_back(s);
            } else if (s == 'Z') {
                Block *z = new ZBlock(obj);
                allblocks.emplace_back(z);
                allchars.emplace_back(s);
            } else if (s == 'T') {
                Block *t = new TBlock(obj);
                allblocks.emplace_back(t);
                allchars.emplace_back(s);
            }
        }
        
        Upcoming::instance()->setVec(allchars, allblocks, 0);

    } else {
        Upcoming::instance()->setlevel(getlevel());  
    }
}

#include "upcoming.h"
#include "block.h"
#include <cstdlib>
#include <string>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"

using namespace std;

Block *Upcoming::getPosBlock(int x) {
 return getVecBlock().at(x);
}

int Upcoming::sizeT(){
return getVecBlock().size();
}

vector<char> Upcoming::getNextBlocks() {
  if (level == 0){ return upcoming;}
   else  {return upcoming2;}
}

int Upcoming::getlevel() {
	return this->level;
}

void Upcoming::setlevel(int level){
 this->level = level; 
}

void Upcoming::updatenextblock(int level, double seed, bool isseed, Board *obj) {
    if (level == 0) {
        //do nothing vec return same
    } else if (level == 1) {


        if (isseed) {
            srand(seed);
        }
        double prob = (rand() % 100);

        if (prob <= 8.3333333) {
            Block *s = new SBlock(obj);
            b.emplace_back(s);
            upcoming2.emplace_back('S');
            // SBlock();
        } else if (prob > 8.333333 && prob <= 16.6666666) {
            Block *z = new ZBlock(obj);
            b.emplace_back(z);
            upcoming2.emplace_back('Z');
            //ZBlock();
        } else if (prob > 16.6666666 && prob <= 33.333333) {
            Block *i = new IBlock(obj);
            b.emplace_back(i);
            upcoming2.emplace_back('I');
            //IBLock();
        } else if (prob > 33.333333 && prob <= 50) {
            Block *j = new JBlock(obj);
            b.emplace_back(j);
            upcoming2.emplace_back('J');
            //JBlock();
        } else if (prob > 50 && prob <= 66.666666) {
            Block *l = new LBlock(obj);
            b.emplace_back(l);
            upcoming2.emplace_back('L');
            //LBlock();
        } else if (prob > 66.6666666 && prob <= 83.33333333) {
            Block *o = new OBlock(obj);
            b.emplace_back(o);
            upcoming2.emplace_back('O');
            //OBlock();
        } else {
            Block *t = new TBlock(obj);
            b.emplace_back(t);
            upcoming2.emplace_back('T');
            //TBlock();
        }
    } else if (level == 2) {
        if (isseed) {
            (srand(seed));
        }
        double prob = rand() % 100;


        if (prob <= 14.2857) {
            Block *i = new IBlock(obj);
            b.emplace_back(i);
            upcoming2.emplace_back('I');
        } else if (prob > 14.2857 && prob <= 28.5714) {
            Block *j = new JBlock(obj);
            b.emplace_back(j);
            upcoming2.emplace_back('J');
        } else if (prob > 28.5714 && prob <= 42.857124) {
            Block *l = new LBlock(obj);
            b.emplace_back(l);
            upcoming2.emplace_back('L');
        } else if (prob > 42.857124 && prob <= 57.142857) {
            Block *o = new OBlock(obj);
            b.emplace_back(o);
            upcoming2.emplace_back('O');
        } else if (prob > 57.142857 && prob <= 71.42857) {
            Block *s = new SBlock(obj);
            b.emplace_back(s);
            upcoming2.emplace_back('S');
        } else if (prob > 71.42857 && prob <= 85.714285) {
            Block *z = new ZBlock(obj);
            b.emplace_back(z);
            upcoming2.emplace_back('Z');
        } else {
            Block *t = new TBlock(obj);
            b.emplace_back(t);
            upcoming2.emplace_back('T');
        }
    } else if (level == 3) {
        if (isseed) {
            (srand(seed));
        }
        double prob = rand() % 100;


        if (prob <= 11.11111) {
            Block *i = new IBlock(obj);
            b.emplace_back(i);
            upcoming2.emplace_back('I');
        } else if (prob > 11.11111 && prob <= 22.22222) {
            Block *j = new JBlock(obj);
            b.emplace_back(j);
            upcoming2.emplace_back('J');
        } else if (prob > 22.22222 && prob <= 33.33333) {
            Block *l = new LBlock(obj);
            b.emplace_back(l);
            upcoming2.emplace_back('L');
        } else if (prob > 33.33333 && prob <= 44.44444) {
            Block *o = new OBlock(obj);
            b.emplace_back(o);
            upcoming2.emplace_back('O');
        } else if (prob > 44.44444 && prob <= 66.66666) {
            Block *s = new SBlock(obj);
            b.emplace_back(s);
            upcoming2.emplace_back('S');
        } else if (prob > 66.66666 && prob <= 88.88888) {
            Block *z = new ZBlock(obj);
            b.emplace_back(z);
            upcoming2.emplace_back('Z');
        } else {
            Block *t = new TBlock(obj);
            b.emplace_back(t);
            upcoming2.emplace_back('T');
        }
    }
}

Upcoming *Upcoming::instance() {
  if (!singleton_instance) singleton_instance = new Upcoming{};
  return singleton_instance;
}

vector<char> Upcoming::getVec() {
    return this->upcoming;
}

void Upcoming::setVec(vector<char> v, vector<Block *> b, int lev)  {
    this->upcoming = v;
    this->b = b;
    this->level = lev;
}

vector<Block *> Upcoming::getVecBlock() {
    return this->b;
}

/*
void setVecBlock(std::vector<Block *> obj) {
    this->b = obj;
}
 */

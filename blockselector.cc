#include "blockselector.h"
#include <sstream>

int Blockselector::getlevel(){
    return level;
}

string Blockselector::getfile0(){
    return file0;
}

string Blockselector::getfile3(){
    return file3;
}

void Blockselector::runlevel(){
    if(getlevel() == 0){
        ifstream f(getfile0());
        string s;
        vector<char> allblocks;
        int counter;
        while(f>>s){
            if(s=="I"){
                IBlock();
            allblocks.emplace(allblocks.begin() + counter,s);    
            }(s == "J"){
                JBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }(s == "L"){
                LBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }(s == "O"){
                OBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }(s == "S"){
                SBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }(s == "Z"){
                ZBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }(s == "T"){
                TBlock();
                allblocks.emplace(allblocks.begin() + counter,s); 
            }
        }
        Upcoming::Instance()->setNextBlocks() = allblocks; 
    }
}

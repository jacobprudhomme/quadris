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
     }else if(getlevel() == 1){
        int prob = (srand(seed) % 100);
        int next = (srand(seed) % 100);
        if(prob<=8.3333333){
            SBlock();
        }else if(prob>8.333333 && prob<=16.6666666){
            ZBlock();
        }else if(prob>16.6666666 && prob<= 33.333333){
            IBLock();
        }else if(prob>33.333333 && prob<=50){
            JBlock();
        }else if(prob>50 && prob<=66.666666){
            LBlock();
        }else if(prob>66.6666666 && prob <=83.33333333){
            OBlock();
        }else{
            TBlock();
        }
        
         if(next<=8.3333333){
              Upcoming::Instance()->setNextBlocks() = 'S'; 
            
        }else if(next>8.333333 && next<=16.6666666){
             Upcoming::Instance()->setNextBlocks() = 'Z'; 
        }else if(next>16.6666666 && next<= 33.333333){
             Upcoming::Instance()->setNextBlocks() = 'I'; 
        }else if(next>33.333333 && next<=50){
             Upcoming::Instance()->setNextBlocks() = 'J'; 
        }else if(next>50 && next<=66.666666){
             Upcoming::Instance()->setNextBlocks() = 'L'; 
        }else if(next>66.6666666 && next <=83.33333333){
             Upcoming::Instance()->setNextBlocks() = 'O'; 
        }else{
             Upcoming::Instance()->setNextBlocks() = 'T'; 
        }
}

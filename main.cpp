#include <iostream>
#include <sstream>
#include <string>
#include "sblock.h"
#include "tblock.h"
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    char mult;
    string left = "lef";//left(lef)
    string right = "ri";//right(ri)
    string down = "do";//down(do)
    string cw = "cl";//clockwise(cl)
    string ccw = "co";//counterclockwise(co)
    string drop = "dr";//drop(dr)
    string levelup = "levelu";//levelup(levelu)
    string leveldown = "leveld";//leveldown(leveld)
    string norandom = "n";//norandom(n)
    string random = "ra";//random(ra)
    string sequence = "s"; //sequence fiel(s)
    string restart = "re";//restart(re)
    string hint = "h";//hint(h)
    vector<vector<char> > pie = {{'t','t','t'},{' ','t',' '}};
    TBlock *piece = new TBlock{2,3,1,pie};
    while (cin >> mult) {
        string s;
        cin >> s;

        if(s.compare(0,3,left) == 0){

        }else if(s.compare(0,2,right) == 0){

        }else if(s.compare(0,2,down) == 0){

        }else if(s.compare(0,2,cw) == 0){
          // cout<< piece->prettyprint();
           piece->clockwise();
           cout<< piece->prettyprint();
        }else if(s.compare(0,2,ccw) == 0){
            piece->antiClockwise();
            cout<< piece->prettyprint();
        }else if(s.compare(0,2,drop) == 0){

        }else if(s.compare(0,6,levelup) == 0){

        }else if(s.compare(0,6,leveldown) == 0){

        }else if(s.compare(0,1,norandom) == 0){

        }else if(s.compare(0,1,sequence) == 0){

        }else if(s.compare(0,2,restart) == 0){

        }else if(s.compare(0,1,hint) == 0){

        }else if(s.compare(0,1,"I") == 0){

        }else if(s.compare(0,1,"J") == 0){

        }else if(s.compare(0,1,"O") == 0){

        }else if(s.compare(0,1,"S") == 0){

        }else if(s.compare(0,1,"Z") == 0){

        }else if(s.compare(0,1,"T") == 0){

        }
        //istringstream ss (s);


    }
}
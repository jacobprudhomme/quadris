#include <string>
#include <iostream>

//Simply returns the vector for the x and y cordinates
vector<XYCor> Blocks::getXYCor() {
  vector<XYCor> v;
  for(int i = 0; i < length; ++i) {
    for(int j = 0; j < width; ++j) {
      if(piece[i][j] == 'B') {//or whatever we are looking at in the vector<vector <char>>
        XYCor xy = {i, j};
        v.emplace_back(xy);
      }
    }
  }
}


void Blocks::moveLeft()  {
  vector<XYCor> temp = getXYCor();
  //moving left decrementing x
  for(auto &n : temp) {
    (n.x)--;
  }

  int len = temp.size();
  //we know where in the vector we have chars
  piece.clear();
  //we just need to place them at the right spot which will be
  //subtracting 1 from the current x's location
  int counter = 0;
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < width; ++j) {
      if(counter == len - 1) return;
      if(i == temp[counter].x && j == temp[counter].y) {
        piece[i][j] = 'B'; //or some char which represent that there is a block
        counter++;
      } else {
        piece[i][j] = ' '; //or some char which represent that there is not a block
      }
    }
  }
}



void Blocks::moveRight()  {
  vector<XYCor> temp = getXYCor();
  //moving right incrementing x
  for(auto &n : temp) {
    (n.x)++;
  }

  int len = temp.size();
  //we know where in the vector we have chars
  piece.clear();
  //we just need to place them at the right spot which will be
  //subtracting 1 from the current x's location
  int counter = 0;
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < width; ++j) {
      if(counter == len - 1) return;
      if(i == temp[counter].x && j == temp[counter].y) {
        piece[i][j] = 'B'; //or some char which represent that there is a block
        counter++;
      } else {
        piece[i][j] = ' '; //or some char which represent that there is not a block
      }
    }
  }
}


void Blocks::moveDown() {
  vector<XYCor> temp = getXYCor();
  //moving down incrementing y
  for(auto &n : temp) {
    (n.y)++;
  }

  int len = temp.size();
  //we know where in the vector we have chars
  piece.clear();
  //we just need to place them at the right spot which will be
  //subtracting 1 from the current x's location
  int counter = 0;
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < width; ++j) {
      if(counter == len - 1) return;
      if(i == temp[counter].x && j == temp[counter].y) {
        piece[i][j] = 'B'; //or some char which represent that there is a block
        counter++;
      } else {
        piece[i][j] = ' '; //or some char which represent that there is not a block
      }
    }
  }
}

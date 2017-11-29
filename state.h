#ifndef STATE_H
#define STATE_H

//enum class StateType { NewPiece, Relay, Reply };
//enum class Colour { None, Black, White };
//enum class Direction { NW, N, NE, W, E, SW, S, SE };
enum class Move { Left, Right, Down, CWRotate, CCWRotate };

struct State {
  //StateType type;  // See above
  //Colour colour;   // What colour was the new piece?  (NOT what is my colour)
  //Direction direction;  // In which direction from me is the new piece?
  Move move;
};

#endif

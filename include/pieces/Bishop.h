#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"

class Bishop : public Piece {
public:
  Bishop(int _x, int _y, bool _color) : Piece(_x, _y, _color) {};
};

#endif // Bishop_h
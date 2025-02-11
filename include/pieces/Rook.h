#ifndef Rook_H
#define Rook_H

#include "Piece.h"

class Rook : public Piece {
public:
  Rook(int _x, int _y, bool _color) : Piece(_x, _y, _color) {};
};

#endif // Rook_H
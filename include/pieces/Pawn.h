#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(int _x, int _y, bool _color) : Piece(_x, _y, _color) {};
};

#endif // Pawn_H
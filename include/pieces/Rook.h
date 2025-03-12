#ifndef Rook_H
#define Rook_H

#include "Piece.h"

class Rook : public Piece {
public:
  Rook(uint8_t _inx, bool _black) : Piece(_inx, _black) {};
};

#endif // Rook_H
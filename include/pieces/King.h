#ifndef King_H
#define King_H

#include "Piece.h"

class King : public Piece {
  public:
    uint8_t inx;
    
    King(uint8_t inx, bool _color) : Piece(inx, _color) {}
};

#endif // King_H
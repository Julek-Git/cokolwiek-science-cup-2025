#ifndef King_H
#define King_H

#include "Piece.h"

class King : public Piece {
  public:
    uint8_t inx;
    
    King(uint8_t inx, bool _color) : Piece(inx, _color, 'K',
      { 
        static_cast<Dirs>(Up + Down + Left + Right),
        static_cast<Dirs>(Up + Down + Left + Right)
      }) {}
};

#endif // King_H
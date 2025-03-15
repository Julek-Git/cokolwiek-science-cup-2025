#ifndef Rook_H
#define Rook_H

#include "Piece.h"

class Rook : public Piece 
{
  public:
    Rook(uint8_t _inx, bool _black) : 
    Piece(_inx, 
      _black, 
      'R', 
      { 
        static_cast<Dirs>(Up + Down + Left + Right),
        static_cast<Dirs>(0)
      }) {};
};

#endif // Rook_H
#ifndef Queen_H
#define Queen_H

#include "Piece.h"

class Queen : public Piece {
public:
  Queen(uint8_t _inx, bool _black) : 
  Piece(_inx, _black, 'Q',
    { 
      static_cast<Dirs>(Up + Down + Left + Right),
      static_cast<Dirs>(Up + Down + Left + Right)
    }) {};
};

#endif // Queen_H
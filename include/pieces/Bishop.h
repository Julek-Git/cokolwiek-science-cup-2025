#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"

class Bishop : public Piece {
public:
  Bishop(int _inx, bool _black) : Piece(_inx, _black) {};
};

#endif // Bishop_h
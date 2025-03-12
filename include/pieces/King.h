#ifndef King_H
#define King_H

#include "Piece.h"

class King : public Piece {
public:
  King(int _x, int _y, bool _color) : Piece(_x, _y, _color) {}
};

#endif // King_H
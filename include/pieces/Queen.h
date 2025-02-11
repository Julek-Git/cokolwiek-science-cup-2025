#ifndef Queen_H
#define Queen_H

#include "Piece.h"

class Queen : public Piece {
public:
  Queen(int _x, int _y, bool _color) : Piece(_x, _y, _color) {};
};

#endif // Queen_H
#ifndef Knight_H
#define Knight_H

#include "Piece.h"

class Knight : public Piece {
public:
  Knight(int _x, int _y, bool _color) : Piece(_x, _y, _color) {}

  // ai generated - will be useful in the future
  // bool canMove(int x, int y) const override {
  //   return (x == this->x + 1 && y == this->y + 2) ||
  //          (x == this->x + 2 && y == this->y + 1) ||
  //          (x == this->x + 2 && y == this->y - 1) ||
  //          (x == this->x + 1 && y == this->y - 2) ||
  //          (x == this->x - 1 && y == this->y - 2) ||
  //          (x == this->x - 2 && y == this->y - 1) ||
  //          (x == this->x - 2 && y == this->y + 1) ||
  //          (x == this->x - 1 && y == this->y + 2);
  // }
};

#endif // Knight_H
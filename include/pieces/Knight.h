#ifndef Knight_H
#define Knight_H

#include "Piece.h"

class Knight : public Piece {
public:
  Knight(uint8_t _inx, bool _black) : Piece(_inx, _black) {};

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
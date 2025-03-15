#ifndef Knight_H
#define Knight_H

#include "Piece.h"

class Knight : public Piece {
public:
  Knight(uint8_t _inx, bool _black);
  void move(uint8_t target_inx) override;
  void take(uint8_t target_inx);
private:
  bool validate_move(uint8_t target_inx) override;
  bool validate_take(uint8_t target_inx) override;
};

#endif // Pawn_H
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

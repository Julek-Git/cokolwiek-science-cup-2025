#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(uint8_t _inx, bool _black) : Piece(_inx, _black) {};
  void move(uint8_t target_inx) override;
  void take(uint8_t target_inx);

private:
  bool validate_move(uint8_t target_inx) override;
  bool validate_take(uint8_t target_inx) override;
};

#endif // Pawn_H
#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(uint8_t _inx, bool _black);
  void move(uint8_t target_inx) override;
  void take(uint8_t target_inx);
  bool* get_is_firstmove() {return &is_first_move;}
private:
  bool is_first_move = true;
  bool validate_move(uint8_t target_inx) override;
  bool validate_take(uint8_t target_inx) override;
};

#endif // Pawn_H
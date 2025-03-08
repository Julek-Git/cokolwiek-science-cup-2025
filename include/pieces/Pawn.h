#ifndef Pawn_H
#define Pawn_H

#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(int _x, int _y, bool _color) : Piece(_x, _y, _color) {};
  bool move(int _x, int _y) override;
  bool take(int _x, int _y);

private:
  bool validate_move(int _x, int _y) override;
  bool validate_take(int _x, int _y) override;
};

#endif // Pawn_H
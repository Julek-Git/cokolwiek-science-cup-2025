#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"

class Bishop : public Piece {
public:
  Bishop(uint8_t _inx, bool _black);
  void move(uint8_t target_inx) override;
  void take(uint8_t target_inx);

private:
  bool validate_move(uint8_t target_inx) override;
  bool validate_take(uint8_t target_inx) override;
};

#endif // Bishop_h
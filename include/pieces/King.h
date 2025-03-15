#ifndef King_H
#define King_H

#include "Piece.h"

class King : public Piece {
  public:
    King(uint8_t _inx, bool _black);
    void move(uint8_t target_inx) override;
    void take(uint8_t target_inx);
  private:
    bool validate_move(uint8_t target_inx) override;
    bool validate_take(uint8_t target_inx) override;
  };

#endif // King_H
#ifndef Queen_H
#define Queen_H

#include "Piece.h"

class Queen : public Piece {
  public:
    Queen(uint8_t _inx, bool _black);
    void move(uint8_t target_inx) override;
    void take(uint8_t target_inx);
  private:
    bool validate_move(uint8_t target_inx) override;
    bool validate_take(uint8_t target_inx) override;
  };

#endif // Queen_H
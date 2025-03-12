#ifndef Piece_H
#define Piece_H
#include <cstdint>

class Piece {
  public:
    Piece(uint8_t _inx, bool _black) : inx(_inx), black(_black) {};
    virtual void move(uint8_t target_inx) = 0;
    void take(uint8_t target_inx);
  protected:
    uint8_t inx;
    bool black; // 0 - white, 1 - black

    virtual bool validate_move(uint8_t target_inx) = 0;
    virtual bool validate_take(uint8_t target_inx) = 0;
};

#endif // Piece_H
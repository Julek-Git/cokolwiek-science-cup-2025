#ifndef Piece_H
#define Piece_H

#include <cstdint>
#include "raylib/raylib.h"
#include <iostream>

class Piece {
  public:
    Piece(uint8_t _inx, bool _black) : inx(_inx), is_black(_black) {};
    
    virtual void move(uint8_t target_inx) = 0;
    void take(uint8_t target_inx);
    virtual Texture2D get_texture() = 0;
  protected:
    uint8_t inx;
    bool is_black; // 0 - white, 1 - black
    Texture2D texture;

    virtual bool validate_move(uint8_t target_inx) = 0;
    virtual bool validate_take(uint8_t target_inx) = 0;
    virtual void set_texture() = 0;
};

#endif // Piece_H
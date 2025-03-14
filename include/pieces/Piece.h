#ifndef Piece_H
#define Piece_H

#include <cstdint>
#include "raylib/raylib.h"
#include <iostream>

class Piece {
  public:
    Piece(uint8_t _inx, bool _black);
    virtual void move(uint8_t target_inx) = 0;
    void take(uint8_t target_inx);
  Texture2D get_texture() { return texture; };
  protected:
    uint8_t inx;
    bool is_black; // 0 - white, 1 - black
    Texture2D texture;
    char symbol;
    static uint8_t id;

    virtual bool validate_move(uint8_t target_inx) = 0;
    virtual bool validate_take(uint8_t target_inx) = 0;
    void set_texture(std::string filename);
};

#endif // Piece_H
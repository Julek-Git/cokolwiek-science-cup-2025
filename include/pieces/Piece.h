#ifndef Piece_H
#define Piece_H

#include <cstdint>
#include "raylib/raylib.h"
#include "MenuStyle/StyleInfo.h"
#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <tuple>
// #include "Game/ActionsAndDrawingManager.h"

class ActionsAndDrawingManager;

using string = std::string;

enum Dirs
{
  None = 0b0,
  Up = 0b10,
  Down = 0b01,
  Left = 0b1000,
  Right = 0b100,
};


class Piece {
  public:
    Piece(uint8_t _inx, bool _black, char _symbol, 
      std::array<Dirs, 2> piece_dirs);
    
    virtual void move(uint8_t target_inx) = 0;
    void take(uint8_t target_inx);
    Texture2D get_texture() { return texture; };
    static void set_pieces_theme(string v) {pieces_theme = v;}
    std::array<std::pair<Dirs, uint8_t>, 8>
    get_move_array() { return move_array; };
    void generate_move_array(
      std::array<Piece*, 64>& chessboard,
    ActionsAndDrawingManager* aadm, RenderTexture2D &pos_moves_text);
    void display_move_array();
    static void set_style_info(StyleInfo* _style_info)
    { style_info = _style_info; };
  protected:
    uint8_t inx;
    bool is_black; // 0 - white, 1 - black
    Texture2D texture;
    char symbol;
    uint8_t id = 0;
    static string pieces_theme;
    std::array<Dirs, 2> piece_dirs;
    static StyleInfo* style_info;
    //LeftRightUpDown UpRightDownLeft

    std::array<std::pair<Dirs, uint8_t>, 8> move_array;
    //Up Down Left Right UpLeft UpRight DownLeft DownRight

    
    virtual bool validate_move(uint8_t target_inx) = 0;
    virtual bool validate_take(uint8_t target_inx) = 0;
    void set_texture(string filename);

  private: 
    static uint8_t counter;
};

#endif // Piece_H
#ifndef ACTIONSANDDRAWINGMANAGER_H
#define ACTIONSANDDRAWINGMANAGER_H

#include <pieces/Piece.h>
#include <array>
#include <memory>
#include <iostream>
#include "MenuStyle/StyleInfo.h"
class Game;

class ActionsAndDrawingManager
{
  
  public:
    ActionsAndDrawingManager(Game* _game, 
      int _checkboard_size, 
      int _checkboard_x,  
      int _checkboard_y, 
      string _pieces_theme,
      StyleInfo* style_info);
    // checkboard_size(_checkboard_size), 
    // checkboard_sx(_checkboard_x), 
    // checkboard_sy(_checkboard_y) {};
    
    std::tuple<bool, RenderTexture2D*> ProcessClick(int x, int y);
    uint8_t DrawPieces();
    string get_pieces_theme() {return pieces_theme; };
    void set_pieces_theme(string v) { pieces_theme = v; };
    uint8_t draw_pos_moves
     (uint8_t inx,
      std::array<std::pair<Dirs, uint8_t>, 8>);
    int get_sq_size() {return sq_size; };
    void draw_pos_move(int x, int y);
    StyleInfo* get_style_info() { return style_info; };
    uint8_t ConvertToInx(int x, int y); //konwersja z współrzędnych
    //kliknięcia do indeksu pola na szachownicy
    std::pair<int, int> ConvertToXY(int inx);   
    //na odwrót
    void draw_pos_move_texr();
    void clear_texture();
  private:
    Game* game;
    int checkboard_size;
    int checkboard_sx; //start
    int checkboard_sy;
    int checkboard_ex; //end
    int checkboard_ey;
    int sq_size;
    std::array<Piece*, 64>* chessboard;
    Piece* active_piece;
    StyleInfo* style_info;
    RenderTexture2D pos_move_texr;
    string pieces_theme;
    

    //uint8_t DrawPossibleMoves(std::array<uint8_t, 64>);
    uint8_t DrawMovementThings();
    uint8_t ProcessAction(uint8_t inx);
    void display_move_array( std::array<bool, 64>* move_arr);
    bool process_action(uint8_t inx);
  };

#endif
#ifndef GAME_H
#define GAME_H
#include "Player/Player.h"

#include <pieces/King.h>
#include <pieces/Queen.h>
#include <pieces/Rook.h>
#include <pieces/Bishop.h>
#include <pieces/Knight.h>
#include <pieces/Pawn.h>
#include "Game/ActionsAndDrawingManager.h"

#include <chrono>

class Bond
{
  public:
    int8_t attacker_inx;
    //relatywne pola od króla
    //które jest zagrozone
    int8_t king_rel_pot_move_inx[7]; 
    int8_t defender_inx;
};

class Game {
  public:
    Player* player1;
    Player* player2;
    
    std::array<Piece*, 64> chessboard;
    King* king;

    Game(Player* p1, Player* p2) : player1(p1), player2(p2) {};
    void generate_start_pos();
    void process_action(uint8_t inx);
    void set_aadm(ActionsAndDrawingManager* _aadm);
    void draw_loop();
    std::array<Piece*, 64>*
    get_chessboard() {return &chessboard; };
    void calc_moves(
      std::array<Piece*, 64> chessboard, 
      ActionsAndDrawingManager* aadm, 
      uint8_t inx);
    void debug_func();
    void delete_mem();
    int get_round() {return movecount;}
    void increment_movecount() 
    {
      movecount++;
      is_black_move = !is_black_move;
    }

    bool is_black_move = false;
  private:
    ActionsAndDrawingManager* aadm;
    bool piece_active = false;
    RenderTexture2D* pos_move_texr;
    int movecount = 0;
    void clear_movearrays(std::array<bool, 64>*);
};


#endif


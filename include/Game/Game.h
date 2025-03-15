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
    
    std::array<std::unique_ptr<Piece>, 64> chessboard;
    King* king;

    Game(Player* p1, Player* p2) : player1(p1), player2(p2) {};
    void generate_start_pos();
    void process_action(uint8_t inx);
    void set_aadm(ActionsAndDrawingManager* _aadm,
      DimensionsInfo dim_info);
    void draw_loop();
    std::array<std::unique_ptr<Piece>, 64>*
    get_chessboard() {return &chessboard; };
    void debug_func();
  private:
    ActionsAndDrawingManager* aadm;
};


#endif


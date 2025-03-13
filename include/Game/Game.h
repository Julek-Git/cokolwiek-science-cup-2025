#ifndef GAME_H
#define GAME_H
#include <Game/Player.h>
#include <Game/ActionsAndDrawingManager.h>


#include <pieces/King.h>
#include <pieces/Queen.h>
#include <pieces/Rook.h>
#include <pieces/Bishop.h>
#include <pieces/Knight.h>
#include <pieces/Pawn.h>


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
    Player player1;
    Player player2;
    
    std::array<std::unique_ptr<Piece>, 64> chessboard;
    King* king;

    Game(const Player& p1, const Player& p2, const ActionsAndDrawingManager& aadm);
    void generate_start_pos();
    void display_array();
    void draw_loop();
  private:
    ActionsAndDrawingManager aadm;
};


#endif


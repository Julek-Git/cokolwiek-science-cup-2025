#ifndef ACTIONSANDDRAWINGMANAGER_H
#define ACTIONSANDDRAWINGMANAGER_H

#include <pieces/Piece.h>
#include <array>
#include <memory>
#include <iostream>
class Game;

class ActionsAndDrawingManager
{
  
  public:
    ActionsAndDrawingManager(Game* _game, 
      int _checkboard_size, 
      int _checkboard_x,  
      int _checkboard_y, 
      string _pieces_theme);
    // checkboard_size(_checkboard_size), 
    // checkboard_sx(_checkboard_x), 
    // checkboard_sy(_checkboard_y) {};
    
    bool ProcessClick(int x, int y);
    uint8_t DrawPieces(std::array<std::unique_ptr<Piece>, 64> &chessboard);
    string get_pieces_theme() {return pieces_theme; };
    void set_pieces_theme(string v) { pieces_theme = v; };
    
    int sq_size;
  private:
    Game* game;
    int checkboard_size;
    int checkboard_sx; //start
    int checkboard_sy;
    int checkboard_ex; //end
    int checkboard_ey;
    std::array<std::unique_ptr<Piece>, 64>* chessboard;
    Piece* active_piece;

    string pieces_theme;
    uint8_t ConvertToInx(int x, int y); //konwersja z współrzędnych
    //kliknięcia do indeksu pola na szachownicy
    std::pair<int, int> ConvertToXY(int inx);   
    //na odwrót
   
    uint8_t DrawPossibleMoves(std::array<uint8_t, 64>);
    uint8_t DrawMovementThings();
    uint8_t ProcessAction(uint8_t inx);
    void process_action(uint8_t inx);
  };

#endif
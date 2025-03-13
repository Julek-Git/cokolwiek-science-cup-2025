#ifndef ACTIONSANDDRAWINGMANAGER_H
#define ACTIONSANDDRAWINGMANAGER_H

#include <pieces/Piece.h>
#include <array>
#include <memory>
#include <iostream>
#include "Game/ScreenInfo.h"

class ActionsAndDrawingManager
{
  
  public:
    ActionsAndDrawingManager(int _checkboard_size, int _checkboard_x,  int _checkboard_y,
    ScreenInfo _screen_info);
    // checkboard_size(_checkboard_size), 
    // checkboard_sx(_checkboard_x), 
    // checkboard_sy(_checkboard_y) {};
    bool ProcessClick(int x, int y);
    uint8_t DrawPieces(std::array<std::unique_ptr<Piece>, 64> &chessboard);
  private:
    int checkboard_size;
    int checkboard_sx; //start
    int checkboard_sy;
    int checkboard_ex; //end
    int checkboard_ey;
    int sq_size;
    ScreenInfo screen_info;
    
    uint8_t ConvertToInx(int x, int y); //konwersja z współrzędnych
    //kliknięcia do indeksu pola na szachownicy
    std::pair<int, int> ConvertToXY(int inx);   
    //na odwrót
   
    uint8_t DrawPossibleMoves(std::array<uint8_t, 64>);
    uint8_t DrawMovementThings();
  };

#endif
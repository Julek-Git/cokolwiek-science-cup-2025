#include <Game/Game.h>
#include <iostream>

void Game::generate_start_pos()
{
  for (int k = 0; k < 64; k++)
  {
    chessboard[k] = nullptr;
  }
  for (int i = 8; i < 16; i++)
  {
    chessboard[i] = std::make_unique<Pawn>(i, false);
    chessboard[63 - i] = std::make_unique<Pawn>(63 - i, true);
  }
  //chessboard[7] = std::make_unique<Pawn>(7, true);
  // for (int j = 0; j < 5; j += 3)
  // {
  //   chessboard[j] = std::make_unique<Rook>(false);
  //   chessboard[j + 1] = std::make_unique<Knight>(false);
  //   chessboard[j + 2] = std::make_unique<Bishop>(false);
  //   chessboard[63 - j] = std::make_unique<Rook>(false);
  //   chessboard[63 - j - 1] = std::make_unique<Knight>(false);
  //   chessboard[63 - j - 2] = std::make_unique<Bishop>(false);
  // }
  // chessboard[3] = std::make_unique<Queen>(false);
  // chessboard[4] = std::make_unique<King>(false);
  // chessboard[63 - 4] = std::make_unique<Queen>(true);
  // chessboard[63 - 3] = std::make_unique<King>(true);
  
  
}
void Game::draw_loop()
{
  //BeginDrawing();
    aadm.DrawPieces(chessboard);
  //EndDrawing();
}
void Game::display_array()
{
  for (int i = 0; i < 64; i++)
  {
    if (chessboard[i] == nullptr)
    {
      std::cout << i << ". NIC" << std::endl;
    }
    std::cout << i << ". " << typeid(chessboard[i]).name() << std::endl;
  }
}


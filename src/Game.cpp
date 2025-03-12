#include <Game/Game.h>


Game::Game(const Player& p1, const Player& p2) 
: player1(p1), player2(p2) 
{
  
};
// void Game::generate_start_pos()
// {
//   for (int i = 8; i < 16; i++)
//   {
//     chessboard[i] = std::make_unique<Pawn>(false);
//     chessboard[63 - i] = std::make_unique<Pawn>(true);
//   }
//   for (int j = 0; j < 5; j += 3)
//   {
//     chessboard[j] = std::make_unique<Rook>(false);
//     chessboard[j + 1] = std::make_unique<Knight>(false);
//     chessboard[j + 2] = std::make_unique<Bishop>(false);
//     chessboard[63 - j] = std::make_unique<Rook>(false);
//     chessboard[63 - j - 1] = std::make_unique<Knight>(false);
//     chessboard[63 - j - 2] = std::make_unique<Bishop>(false);
//   }
//   chessboard[3] = std::make_unique<Queen>(false);
//   chessboard[4] = std::make_unique<King>(false);
//   chessboard[63 - 4] = std::make_unique<Queen>(true);
//   chessboard[63 - 3] = std::make_unique<King>(true);

// }

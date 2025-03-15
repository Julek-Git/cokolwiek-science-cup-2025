#include <Game/Game.h>
#include <iostream>

void Game::set_aadm(ActionsAndDrawingManager* _aadm)
{
  aadm = _aadm;

  std::cout << aadm->sq_size << std::endl;
  Piece::set_pieces_theme(aadm->get_pieces_theme());
  Game::generate_start_pos();
}

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
  // chessboard[j] = std::make_unique<Rook>(false);
  chessboard[1] = std::make_unique<Knight>(1, false);
  chessboard[6] = std::make_unique<Knight>(6, false);
  chessboard[63 - 1] = std::make_unique<Knight>(63 - 1, true);
  chessboard[63 - 6] = std::make_unique<Knight>(63 - 6, true);
  chessboard[2] = std::make_unique<Bishop>(2, false);
  chessboard[5] = std::make_unique<Bishop>(5, false);
  chessboard[63 - 2] = std::make_unique<Bishop>(63 - 2, true);
  chessboard[63 - 5] = std::make_unique<Bishop>(63 - 5, true);
  // chessboard[3] = std::make_unique<Queen>(false);
  // chessboard[4] = std::make_unique<King>(false);
  // chessboard[63 - 4] = std::make_unique<Queen>(true);
  // chessboard[63 - 3] = std::make_unique<King>(true);
  
  
}
void Game::process_action(uint8_t inx)
{
  if (chessboard[inx] == nullptr) return; //jesli nie ma tam figury
  Piece* piece = chessboard[inx].get();
}
void Game::draw_loop()
{
  aadm->DrawPieces(chessboard);
}
void Game::debug_func()
{
  chessboard[2]->generate_move_array(chessboard);
  chessboard[2]->display_move_array();
}


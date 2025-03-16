#include <Game/Game.h>
#include <iostream>

void Game::set_aadm(ActionsAndDrawingManager* _aadm)
{
  aadm = _aadm;

  // std::cout << aadm->sq_size << std::endl;
  Piece::set_pieces_theme(aadm->get_pieces_theme());
  Piece::set_style_info(aadm->get_style_info());
  Game::generate_start_pos();
}

void Game::generate_start_pos()
{
  for (int k = 0; k < 64; k++)
  {
    chessboard[k] = nullptr;
  }
  // for (int i = 8; i < 16; i++)
  // {    
  //   chessboard[i] = new Pawn(i, false);
  //   chessboard[63 - i] = new Pawn(63 - i, true);
  // }
  // std::cout << "Podczas kreacji: " << chessboard[8] << std::endl;
  chessboard[0] = new Rook(0, false);
  chessboard[7] = new Rook(7, false);
  chessboard[63] = new Rook(63, true);
  chessboard[63 - 7] = new Rook(63 - 7, true);

  chessboard[1] = new Knight(1, false);
  chessboard[6] = new Knight(6, false);
  chessboard[63 - 1] = new Knight(63 - 1, true);
  chessboard[63 - 6] = new Knight(63 - 6, true);
  chessboard[2] = new Bishop(2, false);
  chessboard[5] = new Bishop(5, false);
  chessboard[63 - 2] = new Bishop(63 - 2, true);
  chessboard[63 - 5] = new Bishop(63 - 5, true);
  
  chessboard[3] = new Queen(3, false);
  chessboard[63 - 4] = new Queen(63 - 4, true);
  chessboard[4] = new King(4, false);
  chessboard[63 - 3] = new King(63 - 3, true);
  
  
}
void Game::process_action(uint8_t inx)
{
  if (chessboard[inx] == nullptr) return; //jesli nie ma tam figury
  Piece* piece = chessboard[inx];
}
void Game::draw_loop()
{
   aadm->DrawPieces(chessboard); //narazie tak potem 
   //na teksturze morze
    
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    piece_active = false;
    aadm->clear_texture();
    Vector2 mouse_pos = GetMousePosition();
    std::tie(piece_active, pos_move_texr) = aadm->ProcessClick(mouse_pos.x, mouse_pos.y);
  }
  if (piece_active) 
      aadm->draw_pos_move_texr();
}
// void Game::debug_func()
// {
//   chessboard[2]->generate_move_array(chessboard, aadm);
//   chessboard[2]->display_move_array();
// }
void Game::delete_mem()
{
  for (int i = 0; i < 64; i++) 
      delete chessboard[i];
}



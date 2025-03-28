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
  for (int i = 8; i < 16; i++)
  {    
    chessboard[i] = new Pawn(i, false);
    chessboard[63 - i] = new Pawn(63 - i, true);
  }
  std::cout << "Podczas kreacji: " << chessboard[8] << std::endl;
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
void Game::calc_moves(
  std::array<Piece*, 64> chessboard, 
  ActionsAndDrawingManager* aadm, 
  uint8_t inx)
  {
    Piece* piece = chessboard[inx];
    const int sq_size = aadm->get_sq_size();
    int8_t _x = 0;
    int8_t _y = 0;
    uint8_t counter = 0;
    //std::cout << piece->get_symbol() << std::endl;
    char symbol = piece->get_symbol();
    bool is_black = piece->get_isblack();
    std::array<std::pair<Dirs, uint8_t>, 8>* move_dirs_arr = 
    piece->get_movedirssarray();
    std::array<bool, 64>* move_arr = piece->get_movearray();
    std::array<Dirs, 2> piece_dirs = piece->get_piecedirs();
    //std::cout << piece_dirs[0] << std::endl;
    int start_pos_x = 0;
    int start_pos_y = 0;
    std::tie(start_pos_x, start_pos_y) = aadm->ConvertToXY(inx);
    int pos_x = start_pos_x;
    int pos_y = start_pos_y;
    int8_t start_x = (int8_t)inx % 8;
    int8_t start_y = (int8_t)inx / 8;
    if (symbol == 'P')
    {
      bool is_first_move = ((Pawn*)piece)->get_is_firstmove();
        std::tie(start_pos_x, start_pos_y) = aadm->ConvertToXY(inx);
        pos_x = start_pos_x;
        pos_y = start_pos_y;
        int8_t dy = is_black ? -1 : 1;
        _y = inx + dy * 8;
        int8_t movecount = is_first_move ? 2 : 1;
        int8_t i = 0;
        std::cout << "movecount = " << (int) movecount << "\t chessboard[_y] = " << chessboard[_y] << "\t_y = " << (int) _y << std::endl;
        for (; 
          i < movecount && 
          chessboard[_y] == nullptr &&
          _y < 63 && _y > 0; 
          i++)
        {
          (*move_arr)[_y] = true;
          pos_y += sq_size * -dy;
          aadm->draw_pos_move(pos_x, pos_y);
          _y += dy * 8;
        }
        i++;
        (*move_dirs_arr)[0] = std::make_pair(Up, i);
        //std::cout << "EloA" << std::endl;
    }
    else if (symbol == 'N')
    {
      std::tie(start_pos_x, start_pos_y) = aadm->ConvertToXY(inx);
      pos_x = start_pos_x;
      pos_y = start_pos_y;
      int8_t dxy[2] = {-1, 1};
      _x = start_x;
      _y = start_y;
      for (int iy = 0; iy < 2 &&
        _y < 63 && _y > 0; iy++)
      {
        pos_y += 2 * sq_size * dxy[iy];
        _y += 2 * 8 * dxy[iy];
        for (int ix = 0; ix < 2
          && _x > 0 && _x < 8 && 
          chessboard[_y * 8 + _x] == nullptr; ix++)
        {
          pos_x += sq_size * dxy[ix];
          pos_x = start_pos_x;
        }
        pos_y = start_pos_y;
        aadm->draw_pos_move(pos_x, pos_y);
        (*move_arr)[_y * 8 + _x] = true;
      }
      for (int jx = 0; jx < 2 && _x < 8 && _x > 0; jx++)
      {
        pos_x += sq_size * dxy[jx];
        _x += dxy[jx];
  
        for (int jy = 0; jy < 2
          && _y > 0 && _y < 63 && 
          chessboard[_y * 8 + _x] == nullptr; jy++)
        {
          pos_y += sq_size * dxy[jy];
          pos_y = start_pos_y;
        }
        pos_y = start_pos_y;
        aadm->draw_pos_move(pos_x, pos_y);
        (*move_arr)[_y * 8 + _x] = true;
      }
    }
    else if (symbol == 'K')
    {
      //std::cout << "Elo3" << std::endl;
      
    }
    else
    {
      //std::cout << "Elo1" << std::endl;
      int start_pos_x = 0;
      int start_pos_y = 0;
      std::tie(start_pos_x, start_pos_y) = aadm->ConvertToXY(inx);
      int pos_x = start_pos_x;
      int pos_y = start_pos_y;
      // std::cout << "start_pox_x: " << start_pos_x << std::endl;
      // std::cout << "inx: " << (int)inx << "symbol: " << symbol << std::endl;
      if (piece_dirs[0] > 1) //jeśli Left lub Right
      {
        counter = 0;
        _x = inx + 1;
        while (chessboard[_x] == nullptr && _x < 8 && _x > 0)
        {
          _x++;
          (*move_arr)[_x] = true;
          pos_x += sq_size;
          aadm->draw_pos_move(pos_x, pos_y);
          counter++;
        }
        if (!(_x < 8 || _x > 0)  && chessboard[_x] == nullptr)
        {
          (*move_arr)[_x++] = true;
        }
        (*move_dirs_arr)[3] = std::make_pair(Right, counter);
        _x = inx - 1;
        counter = 0;
        pos_x = start_pos_x;
        while (chessboard[_x] == nullptr && _x < 8 && _x > 0)
        {
          _x--;
      
          pos_x -= sq_size;

          aadm->draw_pos_move(pos_x, pos_y);
          counter++;
        }
        if (!(_x < 8 || _x > 0)  && chessboard[_x] == nullptr)
        {
          (*move_arr)[_x++] = true;
        }
        (*move_dirs_arr)[2] = std::make_pair(Left, counter);
        pos_x = start_pos_x;
      }
      if (piece_dirs[0] & (Up | Down) < 4) //jeśli Up lub Down
      {
        counter = 0;
        _y = inx + 8;
        while (chessboard[_y] == nullptr && _y < 64 && _y > 0)
        {
          _y += 8;
      
          pos_y -= sq_size;

          aadm->draw_pos_move(pos_x, pos_y);
          counter++;
        }
        if (!(_y < 64 || _y > 0)  && chessboard[_y] == nullptr)
        {
          (*move_arr)[_y + 8] = true;
        }
        (*move_dirs_arr)[0] = std::make_pair(Down, counter);
        pos_y = start_pos_y;
        _y = inx - 8;
        //std::cout << "Y: " << (int)_y << std::endl;
        counter = 0;
        while (chessboard[_y] == nullptr && _y < 64 && _y > 0)
        {
          _y -= 8;
      
          pos_y += sq_size;

          aadm->draw_pos_move(pos_x, pos_y);
          counter++;
        }
        if (!(_y < 64 || _y > 0)  && chessboard[_x] == nullptr)
        {
          (*move_arr)[_y - 8] = true;
        }
        (*move_dirs_arr)[1] = std::make_pair(Up, counter);
        pos_y = start_pos_y;
      }
      if (piece_dirs[1] > 0) //jesli obydwa skosy  
      {
        int8_t dx[4] {-1, 1, -1, 1};
        int8_t dy[4] {1, 1, -1, -1};

        Dirs dir_map[4] = {
          static_cast<Dirs>(Up + Left), 
          static_cast<Dirs>(Up + Right), 
          static_cast<Dirs>(Down + Left),
          static_cast<Dirs>(Down + Right)};

        int8_t start_x = (int8_t)inx % 8;
        int8_t start_y = (int8_t)inx / 8;

        for (int i = 0; i < 4; i++)
        {
          uint8_t counter = 0;
          int8_t _x = start_x;
          int8_t _y = start_y;
          pos_x = start_pos_x;
          pos_y = start_pos_y;
          bool is_piece = false;
          while (true)
          {
              _x += dx[i];
              _y += dy[i];
              (*move_arr)[8 * _y + _x] = true;

              if (_x < 0 || _x >= 8 || _y < 0 || _y >= 8)
                  break;

              int _inx = _y * 8 + _x;
              
              if (chessboard[_inx] != nullptr)
              {
                is_piece = true;
                break;
              }
              pos_x += sq_size * dx[i];
              pos_y -= sq_size * dy[i];
              aadm->draw_pos_move(pos_x, pos_y);
              counter++;
          }
          (*move_dirs_arr)[4 + i] = std::make_pair(dir_map[i], counter);
          if (is_piece)
          {
            int l_inx = (_y + dy[i]) * 8 + (_x + dx[i]);
            (*move_arr)[l_inx] = true;
          }
        }
      }
    }
    EndTextureMode();

}
void Game::delete_mem()
{
  for (int i = 0; i < 64; i++) 
      delete chessboard[i];
}



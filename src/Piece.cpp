#include "pieces/Piece.h"
#include "Game/ActionsAndDrawingManager.h"

uint8_t Piece::counter = 0;

StyleInfo* Piece::style_info = nullptr;

string Piece::pieces_theme = "Normal";

Piece::Piece(uint8_t _inx, bool _black, 
  char _symbol, std::array<Dirs, 2> _piece_dirs) :
 inx(_inx), is_black(_black), id(counter++), 
 symbol(_symbol), piece_dirs(_piece_dirs)
{
  for (int i = 0; i < move_array.size(); i++)
  {
    move_array[i] = std::make_pair(None, (uint8_t)0);
  }
  display_move_array();
  set_texture(string(1, symbol) + ".png");
}

void Piece::set_texture(string filename)
{
  Image image;
  string b_path = "Assets/Sprites/Pieces/" + pieces_theme + "/Black/" + filename;
  string w_path = "Assets/Sprites/Pieces/" + pieces_theme + "/White/" + filename;
  if (is_black) {
    image = LoadImage(b_path.c_str());
  }
  else {
    image = LoadImage(w_path.c_str());
  }
  int sq_size = style_info->get_chessboard_size() / 8;
  ImageResize(&image, 0.6 * sq_size, 0.85 * sq_size);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

void Piece::generate_move_array(
  std::array<Piece*, 64>& chessboard,
  ActionsAndDrawingManager* aadm, RenderTexture2D &pos_moves_text)
{
  BeginTextureMode(pos_moves_text);
  if (symbol != 'N')
  {
    int start_pos_x = 0;
    int start_pos_y = 0;
    std::tie(start_pos_x, start_pos_y) = aadm->ConvertToXY(inx);
    int pos_x = start_pos_x;
    int pos_y = start_pos_y;
    const int sq_size = aadm->get_sq_size();
    // std::cout << "start_pox_x: " << start_pos_x << std::endl;
    // std::cout << "inx: " << (int)inx << "symbol: " << symbol << std::endl;
    if (piece_dirs[0] > 1) //jeśli Left lub Right
    {
      uint8_t counter = 0;
      int8_t _x = inx + 1;
      while (chessboard[_x] == nullptr && _x < 8 && _x > 0)
      {
        _x++;
    
        pos_x += sq_size;

        aadm->draw_pos_move(pos_x, pos_y);
        counter++;
      }
      move_array[3] = std::make_pair(Right, counter);
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
      move_array[2] = std::make_pair(Left, counter);
      pos_x = start_pos_x;
    }
    if (piece_dirs[0] & (Up | Down) < 4) //jeśli Up lub Down
    {
      uint8_t counter = 0;
      int8_t _y = inx + 8;
      while (chessboard[_y] == nullptr && _y < 64 && _y > 0)
      {
        _y += 8;
    
        pos_y -= sq_size;

        aadm->draw_pos_move(pos_x, pos_y);
        counter++;
      }
      move_array[0] = std::make_pair(Down, counter);
      pos_y = start_pos_y;
      _y = inx - 8;
      std::cout << "Y: " << (int)_y << std::endl;
      counter = 0;
      while (chessboard[_y] == nullptr && _y < 64 && _y > 0)
      {
        _y -= 8;
    
        pos_y += sq_size;

        aadm->draw_pos_move(pos_x, pos_y);
        counter++;
      }
      move_array[1] = std::make_pair(Up, counter);
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

        while (true)
        {
            _x += dx[i];
            _y += dy[i];

            if (_x < 0 || _x >= 8 || _y < 0 || _y >= 8)
                break;

            int _inx = _y * 8 + _x;
            
            if (chessboard[_inx] != nullptr)
                break;
            pos_x += sq_size * dx[i];
            pos_y -= sq_size * dy[i];
            aadm->draw_pos_move(pos_x, pos_y);
            counter++;
        }
        move_array[4 + i] = std::make_pair(dir_map[i], counter);
      }

    }
  }
  EndTextureMode();
}
void Piece::display_move_array()
{
  // for (int i = 0; i < move_array.size(); i++)
  // {
  //   std::cout << i << ". " << move_array[i].first << " | " 
  //   << (int)move_array[i].second << std::endl;
  // }
}

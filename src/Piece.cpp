#include "pieces/Piece.h"

uint8_t Piece::counter = 0;

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
  ImageResize(&image, image.width / 8.5, image.height / 8.5);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

void Piece::generate_move_array(
  std::array<std::unique_ptr<Piece>, 64> &chessboard
)
{
  if (symbol != 'N')
  {
    if (piece_dirs[0] > 1) //jeśli Left lub Right
    {
      int8_t _x = inx;
      for (; chessboard[_x] == nullptr && _x < 8; _x++);
      move_array[3] = std::make_pair(Right, _x);
      _x = inx;
      for (; chessboard[_x] == nullptr && _x > -1; _x--);
      move_array[2] = std::make_pair(Left, _x);
    }
    if (piece_dirs[0] & (Up + Down) < 2) //jeśli Up lub Down
    {
      int8_t _y = inx;
      for (; chessboard[_y] == nullptr && _y * 8 < 64; _y += 8);
      move_array[0] = std::make_pair(Down, _y);
      _y = inx;
      for (; chessboard[_y] == nullptr && _y * 8 > -1; _y -= 8);
      move_array[1] = std::make_pair(Up, _y);
    }
    if (piece_dirs[1] > 0) //jesli obydwa skosy  
    {
      int8_t _x = (int8_t)inx % 8;
      int8_t _y = (int8_t)inx / 8;
      uint8_t counter = 0;
      while (chessboard[(_y + 1) * 8 + (_x + 1)] == nullptr
      && _x + 1 < 8 && (_y + 1) * 8 < 64)
      {
        _x++;
        _y++;
        counter++;
      }
      move_array[5] = std::make_pair(static_cast<Dirs>(Up + Right), counter);

      _x = inx % 8;
      _y = inx / 8;
      counter = 0;
      while (chessboard[(_y - 1) * 8 + (_x - 1)] == nullptr
      && _x - 1 > -1 && (_y - 1) * 8 > -1)
      {
        _x--;
        _y--;
        std::cout << _x << std::endl;
        std::cout << _y << std::endl;
        counter++;
      }
      move_array[6] = std::make_pair(static_cast<Dirs>(Down + Left), counter);

      _x = inx % 8;
      _y = inx / 8;
      counter = 0;
      while (chessboard[(_y + 1) * 8 + (_x - 1)] == nullptr
        && _x - 1 > -1 && (_y + 1) * 8 < 64)
      {
        _x--;
        _y++;
        counter++;
      }

      move_array[4] = std::make_pair(static_cast<Dirs>(Up + Left), counter);
    
      _x = inx % 8;
      _y = inx / 8;
      counter = 0;
      while (chessboard[(_y - 1) * 8 + (_x + 1)] == nullptr
        && _x + 1 < 8 && (_y - 1) * 8 > -1)
      {
        _x++;
        _y--;
        counter++;
      }
      move_array[7] = std::make_pair(static_cast<Dirs>(Down + Right), counter);
    }
  }  
}
void Piece::display_move_array()
{
  for (int i = 0; i < move_array.size(); i++)
  {
    std::cout << i << ". " << move_array[i].first << " | " 
    << (int)move_array[i].second << std::endl;
  }
}

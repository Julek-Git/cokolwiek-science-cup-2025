#include "pieces/Piece.h"

uint8_t Piece::counter = 0;

DimensionsInfo Piece::dim_info = 0;

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
  int sq_size = dim_info.get_chessboard_size() / 8;
  ImageResize(&image, image.width / (sq_size / 12), image.height / (sq_size / 12));
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
    if (piece_dirs[0] & (Up | Down) < 2) //jeśli Up lub Down
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

        while (true)
        {
            _x += dx[i];
            _y += dy[i];

            if (_x < 0 || _x >= 8 || _y < 0 || _y >= 8)
                break;

            int _inx = _y * 8 + _x;
            
            if (chessboard[_inx] != nullptr)
                break;

            counter++;
        }
        move_array[4 + i] = std::make_pair(dir_map[i], counter);
      }
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

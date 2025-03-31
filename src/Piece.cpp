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
  for (int i = 0; i < move_arr.size(); i++)
  {
    move_arr[i] = false;
  }
  for (int i = 0; i < move_dirs_arr.size(); i++)
  {
    move_dirs_arr[i] = std::make_pair(None, (uint8_t)0);
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

void Piece::display_move_array()
{
  // for (int i = 0; i < move_array.size(); i++)
  // {
  //   std::cout << i << ". " << move_array[i].first << " | " 
  //   << (int)move_array[i].second << std::endl;
  // }
}

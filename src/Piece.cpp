#include "pieces/Piece.h"

Piece::Piece(uint8_t _inx, bool _black) :
 inx(_inx), is_black(_black) 
{
  id++;
  set_texture(symbol + ".png");
}

void Piece::set_texture(std::string filename)
{
  Image image;
  std::string b_path = "Assets/Sprites/Pieces/Normal/Black/" + filename;
  std::string w_path = "Assets/Sprites/Pieces/Normal/White/" + filename;
  if (is_black) {
    image = LoadImage(b_path.c_str());
  }
  else {
    image = LoadImage(w_path.c_str());
  }
  ImageResize(&image, image.width / 10, image.height / 10);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}
#include <Game/ActionsAndDrawingManager.h>
#include "Game/Game.h"
#include <math.h>

ActionsAndDrawingManager::ActionsAndDrawingManager(
  Game* _game, 
  int _checkboard_size, int _checkboard_x,  
  int _checkboard_y, 
  string _pieces_theme,
  StyleInfo* _style_info) : 
  checkboard_size(_checkboard_size), checkboard_sx(_checkboard_x),
  checkboard_sy(_checkboard_y), pieces_theme(_pieces_theme), 
  game(_game), style_info(_style_info)
{
  chessboard = game->get_chessboard();
  checkboard_ex = checkboard_sx + checkboard_size;
  checkboard_ey = checkboard_sy + checkboard_size;
  sq_size = checkboard_size / 8; //BO 8 KWADRATOW NA 8 KWADRATOW
  //std::cout << "Jestem w " << game << " i jestem: " << this << std::endl;
  pos_move_texr = LoadRenderTexture(checkboard_size, checkboard_size);  
};
std::tuple<bool, RenderTexture2D*> ActionsAndDrawingManager::ProcessClick(int x, int y)
{
  if (x < checkboard_ex && y < checkboard_ey && x > checkboard_sx && y > checkboard_sy)
    return {process_action(ConvertToInx(x, y)), &pos_move_texr};
  else return {false, &pos_move_texr};
  //std::cout << this << std::endl;
}
void ActionsAndDrawingManager::draw_pos_move_texr()
{
  //std::cout << pos_move_texr.texture.id << std::endl;
  DrawTextureRec(
    pos_move_texr.texture, 
    Rectangle{0, 0, (float)checkboard_size, (float)-checkboard_size },
    Vector2{(float)checkboard_sx, (float)checkboard_sy}, 
    WHITE
  );
}
void ActionsAndDrawingManager::clear_texture()
{
  BeginTextureMode(pos_move_texr);
    ClearBackground(BLANK); 
  EndTextureMode();
}
bool ActionsAndDrawingManager::process_action(uint8_t inx)
{
  Piece* potential_piece = (*chessboard)[inx];
  if (potential_piece == nullptr) return false;

  active_piece = potential_piece;
  //std::cout << "Nie jestem nullem tylko: " << potential_piece << std::endl;
  game->calc_moves(*chessboard, this, inx);
  return true;
}
uint8_t ActionsAndDrawingManager::ConvertToInx(int x, int y)
{
  int r_x = x - checkboard_sx;
  int r_y = checkboard_size - y - checkboard_sy;
  //std::cout << "r_y: " << r_y  << "sq_size: " << sq_size << std::endl;
  int square_pos_x = r_x / sq_size;
  int square_pos_y = std::ceil((float)r_y / sq_size);
  //std::cout << "square_pos_y: " << square_pos_y << std::endl;
  //3 4 
  uint8_t inx = 8 * square_pos_y + square_pos_x;
  //std::cout << "Inx: " << (int)inx << std::endl;
  return inx;
}
std::pair<int, int> ActionsAndDrawingManager::ConvertToXY(int inx)
{
  //std::cout << this << std::endl;
  int pos_x = inx % 8 * sq_size + checkboard_sx;
  int pos_y = checkboard_ey - inx / 8 * sq_size - sq_size;
  // int pos_y = inx / 8 * sq_size - sq_size;
  //std::cout << "pos_y: " << pos_y << std::endl;
  return {pos_x, pos_y};
}

uint8_t ActionsAndDrawingManager::DrawPieces(
  std::array<Piece*, 64> &chessboard)
{
  int pos_x = 0;
  int pos_y = 0;

  for (int j = 0; j < chessboard.size(); j++)
  {
    if (chessboard[j] == nullptr) continue;  
    Texture2D texture = chessboard[j]->get_texture();
    std::tie(pos_x, pos_y) = ConvertToXY(j);  
    pos_x += (sq_size - texture.width) / 2;
    pos_y += (sq_size - texture.height) / 2;
    DrawTexture(texture, pos_x, pos_y, WHITE);  
  }
  return 0;
}
void ActionsAndDrawingManager::draw_pos_move(int x, int y)
{
  // const int size = 0.5 * sq_size;
  // int pos_x = x + sq_size - size / 2;
  // int pos_y = y + sq_size - size / 2;
  //std::cout << "Dziala" << std::endl;
  BeginTextureMode(pos_move_texr);
  const int center = 0.1 * sq_size;
  const int radius = 0.2 * sq_size;
  int pos_x = x + center;
  int pos_y = y + center;

  DrawCircle(pos_x, pos_y, radius, GRAY);
  EndTextureMode();
}
// uint8_t ActionsAndDrawingManager::draw_pos_moves(uint8_t inx,
//   std::array<std::pair<Dirs, uint8_t>, 8>)
// {
//   int pos_x = 0;
//   int pos_y = 0;
//   std::tie(pos_x, pos_y) = ConvertToXY(inx);


// }
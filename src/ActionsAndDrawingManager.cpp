#include <Game/ActionsAndDrawingManager.h>
#include <Game/ScreenInfo.h>
#include "Game/Game.h"

ActionsAndDrawingManager::ActionsAndDrawingManager(
  Game* _game, 
  int _checkboard_size, int _checkboard_x,  
  int _checkboard_y,
  ScreenInfo _screen_info, 
  string _pieces_theme) : 
  checkboard_size(_checkboard_size), checkboard_sx(_checkboard_x),
  checkboard_sy(_checkboard_y), screen_info(_screen_info),
  pieces_theme(_pieces_theme), game(_game)
{
  chessboard = game->get_chessboard();
  checkboard_ex = checkboard_sx + checkboard_size;
  checkboard_ey = checkboard_sy + checkboard_size;
  sq_size = checkboard_size / 8; //BO 8 KWADRATOW NA 8 KWADRATOW
  std::cout << "Jestem w " << game << " i jestem: " << this << std::endl;
};
bool ActionsAndDrawingManager::ProcessClick(int x, int y)
{
  if (x < checkboard_ex && y < checkboard_ey)
    process_action(ConvertToInx(x, y));
  else return false;
}
void ActionsAndDrawingManager::process_action(uint8_t inx)
{
  if ((*chessboard)[inx] == nullptr) return;
  active_piece = (*chessboard)[inx].get();

  
}
uint8_t ActionsAndDrawingManager::ConvertToInx(int x, int y)
{
  int r_x = x - checkboard_sx;
  int r_y = y - checkboard_ey;

  int square_pos_x = r_x / sq_size;
  int square_pos_y = r_y / sq_size;

  //3 4 
  uint8_t inx = 8 * square_pos_y + square_pos_x;
  return inx;
}
std::pair<int, int> ActionsAndDrawingManager::ConvertToXY(int inx)
{
  int pos_x = inx % 8 * sq_size + checkboard_sx;
  int pos_y = checkboard_ey - inx / 8 * sq_size - sq_size;
  //centrowanie fotki

  return {pos_x, pos_y};
}
uint8_t ActionsAndDrawingManager::DrawPieces(
  std::array<std::unique_ptr<Piece>, 64> &chessboard)
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

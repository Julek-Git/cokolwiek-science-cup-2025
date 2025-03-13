#include <Game/ActionsAndDrawingManager.h>
#include <Game/ScreenInfo.h>

ActionsAndDrawingManager::ActionsAndDrawingManager(int _checkboard_size, int _checkboard_x,  int _checkboard_y,
  ScreenInfo _screen_info) : 
checkboard_size(_checkboard_size), checkboard_sx(_checkboard_x),
 checkboard_sy(_checkboard_y), screen_info(_screen_info)
{
  checkboard_ex = checkboard_sx + checkboard_size;
  checkboard_ey = checkboard_sy + checkboard_size;
  sq_size = checkboard_size / 8; //BO 8 KWADRATOW NA 8 KWADRATOW
};

bool ActionsAndDrawingManager::ProcessClick(int x, int y)
{
  if (x < checkboard_ex && y < checkboard_ey)
    ConvertToInx(x, y);
  else return false;
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
  int pos_x = inx % 8 * sq_size + checkboard_sx + sq_size / 4.75;
  int pos_y = checkboard_ey - inx / 8 * sq_size - sq_size / 1.25;

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
    DrawTexture(texture, pos_x, pos_y, WHITE);  
    
    //DrawRectangle(pos_x, pos_y, 50, 50, YELLOW);

  }

  return 0;
}

// uint8_t ActionsAndDrawingManager::ConvertToInx(int x, int y)
// {
//   int r_x = x - checkboard_sx;
//   int r_y = y - checkboard_ey;

//   int square_pos_x = r_x / sq_size * sq_size + sq_size / 2;
//   int square_pos_y  = r_y / sq_size * sq_size + sq_size / 2;



// }
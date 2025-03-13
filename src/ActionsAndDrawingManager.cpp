#include <Game/ActionsAndDrawingManager.h>

ActionsAndDrawingManager::ActionsAndDrawingManager(int _checkboard_size, int _checkboard_x,  int _checkboard_y) : 
checkboard_size(_checkboard_size), checkboard_sx(_checkboard_x), checkboard_sy(_checkboard_y) 
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
  int pos_x = inx % 8 * sq_size + checkboard_sx;
  int pos_y = inx / 8 * sq_size + checkboard_sy;

  return {pos_x, pos_y};
}
uint8_t ActionsAndDrawingManager::DrawPieces(
  std::array<std::unique_ptr<Piece>, 64> &chessboard)
{
  
  int pos_x = 0;
  int pos_y = 0;
  //std::cout << "Jestem tu " << chessboard.size() << std::endl;

  for (int k = 0; k < 64; k++)
  {
    
  }
  int k = 0;
  while (k < 64)
  {
    std::cout << "Jestem tu k" << k << std::endl;
    k++;
  }

  // for (int j = 0; j < 64; j++)
  // {
  //   // bool express = i < (int)(chessboard.size() - 1);
    
  //   // if (chessboard[j] == nullptr) continue; 
  
  //   // Texture2D texture = chessboard[j]->get_texture();
    
  //   // std::tie(pos_x, pos_y) = ConvertToXY(j);
    
  //   // DrawTexture(texture, pos_x, pos_y, WHITE);   
  // }

  return 0;
}

// uint8_t ActionsAndDrawingManager::ConvertToInx(int x, int y)
// {
//   int r_x = x - checkboard_sx;
//   int r_y = y - checkboard_ey;

//   int square_pos_x = r_x / sq_size * sq_size + sq_size / 2;
//   int square_pos_y  = r_y / sq_size * sq_size + sq_size / 2;



// }
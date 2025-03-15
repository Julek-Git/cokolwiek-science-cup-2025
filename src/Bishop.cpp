#include <Pieces/Bishop.h>

Bishop::Bishop(uint8_t _inx, bool _black) : 
Piece(_inx, _black, 'B', { 
  static_cast<Dirs>(0),
  static_cast<Dirs>(Up + Down + Left + Right)
}) {};

void Bishop::move(uint8_t target_inx) 
{
  
}

void Bishop::take(uint8_t target_inx) 
{
  
}
bool Bishop::validate_move(uint8_t target_inx) 
{
  return false;
}
bool Bishop::validate_take(uint8_t target_inx) 
{
  return false;
}
#include "pieces/Queen.h"


Queen::Queen(uint8_t _inx, bool _black) : 
Piece(_inx, _black, 'Q',
  { 
    static_cast<Dirs>(Up + Down + Left + Right),
    static_cast<Dirs>(Up + Down + Left + Right)
  }) {};

void Queen::move(uint8_t target_inx) 
{
  
}

void Queen::take(uint8_t target_inx) 
{
  
}
bool Queen::validate_move(uint8_t target_inx) 
{
  return false;
}
bool Queen::validate_take(uint8_t target_inx) 
{
  return false;
}
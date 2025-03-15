#include "pieces/Knight.h"

Knight::Knight(uint8_t _inx, bool _black) 
: Piece(_inx, _black, 'N',
  { 
    static_cast<Dirs>(0),
    static_cast<Dirs>(0)
  }) {};

void Knight::move(uint8_t target_inx) 
{
  
}

void Knight::take(uint8_t target_inx) 
{
  
}
bool Knight::validate_move(uint8_t target_inx) 
{
  return false;
}
bool Knight::validate_take(uint8_t target_inx) 
{
  return false;
}
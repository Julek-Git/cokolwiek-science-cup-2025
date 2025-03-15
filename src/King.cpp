#include "pieces/King.h"

King::King(uint8_t inx, bool _color) : 
Piece(inx, _color, 'K',
  { 
    static_cast<Dirs>(Up + Down + Left + Right),
    static_cast<Dirs>(Up + Down + Left + Right)
  }) {};

void King::move(uint8_t target_inx) 
{
  
}
void King::take(uint8_t target_inx) 
{
  
}
bool King::validate_move(uint8_t target_inx) 
{
  return false;
}
bool King::validate_take(uint8_t target_inx) 
{
  return false;
}
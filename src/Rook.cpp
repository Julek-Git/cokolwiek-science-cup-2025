#include "pieces/Rook.h"

Rook::Rook(uint8_t _inx, bool _black) : 
Piece(_inx, _black, 'R', 
  { 
    static_cast<Dirs>(Up+Down+Left+Right),
    static_cast<Dirs>(0)
  }) {};


void Rook::move(uint8_t target_inx) 
{
  
}

void Rook::take(uint8_t target_inx) 
{
  
}
bool Rook::validate_move(uint8_t target_inx) 
{
  return false;
}
bool Rook::validate_take(uint8_t target_inx) 
{
  return false;
}
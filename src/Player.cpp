#include <Game/Player.h>

Player::Player
(
  bool black, 
  std::chrono::seconds time,
  PlayerType player_type,
  char name[15]
)
{
  this->black = black;
  this->time = time;
  this->player_type = player_type;
};
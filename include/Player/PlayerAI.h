#ifndef PlayerAI_H
#define PlayerAI_H

#include "Player.h"

class PlayerAI : public Player {
public:
	PlayerAI(
    bool is_black, 
    std::chrono::seconds time,
    std::string name
  ) : Player(is_black, time, name) {};

  void make_move() override;
  
};

#endif
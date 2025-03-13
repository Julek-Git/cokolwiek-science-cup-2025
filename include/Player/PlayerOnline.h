#ifndef PlayerOnline_H
#define PlayerOnline_H

#include "Player.h"

class PlayerOnline : public Player {
public:
	PlayerOnline(
    bool is_black, 
    std::chrono::seconds time,
    std::string name
  ) : Player(is_black, time, name) {};

  void make_move() override;
  
};


#endif
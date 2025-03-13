#ifndef PlayerOffline_H
#define PlayerOffline_H

#include "Player.h"

class PlayerOffline : public Player {
public:
	PlayerOffline(
    bool is_black, 
    std::chrono::seconds time,
    std::string name
  ) : Player(is_black, time, name) {};

  void make_move() override;
  
};

#endif
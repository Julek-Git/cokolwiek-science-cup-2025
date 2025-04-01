#ifndef PlayerOnline_H
#define PlayerOnline_H

#include "Player.h"

class PlayerOnline : public Player {
public:
	PlayerOnline(
    bool is_black, 
    std::chrono::seconds time,
    std::string name,
    std::string _ip,
    int _port
  ) : Player(is_black, time, name), ip(_ip), port(_port) {};

  void make_move() override;

private:
  std::string ip;
  int port;
};


#endif
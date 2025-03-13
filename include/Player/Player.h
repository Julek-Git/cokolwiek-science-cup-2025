#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <string>


class Player {
public:
  std::chrono::seconds time;
  bool is_black;
  
  std::string name;
  int16_t elo; //ranking elo
  int wins;
  int draws;
  int loses;

  Player (
    bool _is_black, 
    std::chrono::seconds _time,
    std::string _name
  ) : is_black(_is_black), time(_time), name(_name) {};

  virtual void make_move() = 0;
};

#endif
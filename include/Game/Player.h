#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>

enum class PlayerType
{
  OfflineHuman,
  AI,
  OnlineHuman
};
class Player 
{
  public:
    std::chrono::seconds time;
    bool black;
    
    PlayerType player_type;
    char name[15];
    int16_t elo; //ranking elo
    int wins;
    int draws;
    int loses;
    Player
    (
      bool black, 
      std::chrono::seconds time,
      PlayerType player_type,
      char name[15]
    );
};
#endif
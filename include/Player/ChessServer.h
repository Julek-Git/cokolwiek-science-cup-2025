#ifndef CHESSSERVER_H
#define CHESSSERVER_H

#include "Player/Player.h"

class ChessServer : public Player {
public:
  ChessServer(
    bool _is_black,
    std::chrono::seconds _time,
    const std::string name,
    int _port
  ) : Player(_is_black, time, name), port(_port) {}

  void make_move() override;
private:
  int port;
};

#endif // CHESSSERVER_H

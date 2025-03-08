#ifndef Piece_H
#define Piece_H

class Piece {
public:
  Piece(int _x, int _y, bool _color) : x(_x), y(_y), color(_color) {};
  virtual bool move(int _x, int _y) = 0;
  bool take(int _x, int _y) { return move(_x, _y); }
protected:
  int x;
  int y;
  bool color; // 0 - white, 1 - black
  
  virtual bool validate_move(int _x, int _y) = 0;
  virtual bool validate_take(int _x, int _y) = 0;
};

#endif // Piece_H
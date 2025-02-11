#ifndef Piece_H
#define Piece_H

class Piece {
public:
  Piece(int _x, int _y, bool _color);
  virtual bool move(int _x, int _y);
  bool take(int _x, int _y) { return move(_x, _y); }
protected:
  int x;
  int y;
  bool color; // 0 - white, 1 - black
  
  bool validate_move(int _x, int _y);
  bool validate_take(int _x, int _y);
};

#endif // Piece_H
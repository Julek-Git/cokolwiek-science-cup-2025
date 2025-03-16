#ifndef DIMENSIONSINFO_H
#define DIMENSIONSINFO_H

#include <raylib/raylib.h>

class StyleInfo
{
  public:
    StyleInfo(int _chessboard_size,
    Color _white, Color _black) : 
    chessboard_size(_chessboard_size),
    white(_white), black(_black) {};

    int get_chessboard_size() { return chessboard_size; };
    Color get_chessboard_black() { return black; };
    Color get_chessboard_white() { return white; };
  private:
    int chessboard_size;
    Color black;
    Color white;
};

#endif
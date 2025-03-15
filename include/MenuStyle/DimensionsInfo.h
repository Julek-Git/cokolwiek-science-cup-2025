#ifndef DIMENSIONSINFO_H
#define DIMENSIONSINFO_H

class DimensionsInfo
{
  public:
    DimensionsInfo(int _chessboard_size) : 
    chessboard_size(_chessboard_size) {};
    //screen_width(_screen_width), 
    // screen_height(_screen_height) {};
    // int GetScreenWidth() { return screen_width; }
    // int GetScreenHeight() { return screen_height; }
    int get_chessboard_size() { return chessboard_size; };
  private:
    // int screen_width;
    // int screen_height;
    int chessboard_size;
};

#endif
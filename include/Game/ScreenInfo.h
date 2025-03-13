#ifndef SCREENINFO_H
#define SCREENINFO_H

class ScreenInfo
{
  public:
    ScreenInfo(int _screen_width,
    int _screen_height) : screen_width(_screen_width), 
    screen_height(_screen_height) {};
    int GetScreenWidth() { return screen_width; }
    int GetScreenHeight() { return screen_height; }
  private:
    int screen_width;
    int screen_height;
};

#endif
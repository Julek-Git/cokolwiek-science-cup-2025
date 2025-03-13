#ifndef MENUSTYLE_H
#define MENUSTYLE_H

#include <raylib/raylib.h>
#include "Game/ScreenInfo.h"

class MenuStyle {
  private:
    int width;
    int height;
    int pixels_offset;
    int x;
    int y;
    int font_size;
    int left_border_size;
    int header_border_thickness;
    int header_border_width;
    int margin_top_header_text;
    RenderTexture2D canvas;
    
  public:
    MenuStyle
    (
      int width, int height, 
      int x, int y, 
      int pixels_offset,
      int font_size,
      RenderTexture2D canvas,
      ScreenInfo _screen_info
    );
    
    void draw_menu();
    RenderTexture2D get_canvas();

    ScreenInfo screen_info;
    Color menu_color;
    bool same_border_style;
    Color header_text_color;
    Color header_border_color;
    Color border_color;
    Color timer_background_color;
    Color timer_text_color;
};

#endif  // MenuStyle_h
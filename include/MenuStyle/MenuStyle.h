#ifndef MENUSTYLE_H
#define MENUSTYLE_H

#include <raylib/raylib.h>

class MenuStyle {
  private:
    int width;
    int height;
    int pixels_offset;
    float x;
    float y;
    int font_size;
    int left_border_size;
    int header_border_thickness;
    int header_border_width;
    int margin_top_header_text;
    RenderTexture2D canvas;
    Color menu_color;
    bool same_border_style;
    Color header_text_color;
    Color header_border_color;
    Color border_color;
    Color timer_background_color;
    Color timer_text_color;
  public:
    MenuStyle
    (
      int width, int height, 
      float x, float y, 
      int pixels_offset,
      RenderTexture2D& canvas
    );

    void draw_menu();
};

#endif  // MenuStyle_h
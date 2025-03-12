#include <MenuStyle/MenuStyle.h>
#include <raylib/raylib.h>

MenuStyle::MenuStyle(
  int width, int height, 
  int x, int y, int pixels_offset,
  RenderTexture2D canvas
) 
{
  this->canvas = canvas;
  this->width = width;
  this->height = height;
  this->x = x;
  this->y = y; 

  left_border_size = 0.03 * width;
  this->width = width - left_border_size - pixels_offset;

  header_border_thickness = 0.005 * height;
  header_border_width = 0.01 * width;
  margin_top_header_text = 0.03 * width;
}
void MenuStyle::draw_menu()
{
  BeginTextureMode(canvas);

  int c_x = x;
  int c_y = y;

  DrawRectangle(x, y, left_border_size, height, BLACK);
    
 //c_x += left_border_size + pixels_offset / 2; 
  c_x += left_border_size + pixels_offset / 2;
  DrawRectangle(c_x, c_y, width, height, menu_color);
    //canvas.texture.

 
  //header
  DrawRectangle(c_x + header_border_width , 
    c_y + margin_top_header_text, width - header_border_width * 2
    , header_border_thickness, BLACK); //border top

  DrawText("SZACHY", c_x + width / 2 - font_size * 1.8f, c_y + 
    margin_top_header_text * 2, font_size, header_text_color);

  DrawRectangle(c_x + header_border_width, 
    c_y + margin_top_header_text * 3 + font_size * 0.8, width - header_border_width * 2,
     header_border_thickness, BLACK);

  ////////////////////////////
  //////////////////////////// TIME
  ////////////////////////////
  



  
  EndTextureMode(); 
}

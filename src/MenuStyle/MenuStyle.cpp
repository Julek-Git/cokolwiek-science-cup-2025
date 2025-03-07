#include "MenuStyle/MenuStyle.h"
#include <raylib/raylib.h>

MenuStyle::MenuStyle(int width, int height, float x, float y) {
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
#define RAYGUI_IMPLEMENTATION

#include "raylib/raylib.h"
#include "raylib/raygui.h"
#include <string>
#include "MenuStyle/MenuStyle.h"

// void make_checkboard(int width, int height, RenderTexture2D canvas,  int font_size,
//   float offset_perc_updown[2],
//   float offset_perc_leftright[2], struct Color white_c, struct Color black_c);
void draw_frame(int width, int height, int size, int inner_size, RenderTexture2D canvas, 
  struct Color color, struct Color innerColor);

std::pair<int, int> make_checkboard(int width, int height, int left_offset, int
    down_offset, int font_size, RenderTexture2D canvas, struct Color white_c, struct Color black_c,
    int checkboard_size = -1);

int main() {
  const int screenWidth = 1200;
  const int screenHeight = 800;
  
  InitWindow(screenWidth, screenHeight, "Motorola Science Cup - Szachy");
  SetTargetFPS(60);

  RenderTexture2D checkboard_texture = LoadRenderTexture(screenWidth, screenHeight);  

  int size = 30;
  int outer_size = 20;

  int left_offset = outer_size + size;
  int down_offset = outer_size + size;
  //make_checkboard(screenWidth, screenHeight, chess_board, 20, updown, leftright, WHITE, BLUE);
  draw_frame(screenWidth, screenHeight, size, outer_size, checkboard_texture, BLACK, GREEN);
  int checkboard_size;
  int pixels_offset;
  std::tie(checkboard_size, pixels_offset) = make_checkboard(screenWidth, screenHeight, left_offset, down_offset, 20, checkboard_texture, WHITE, BLUE);
  
  //UI
  float menu_ui_start_x = left_offset + checkboard_size;
  float menu_ui_start_y = down_offset + pixels_offset / 2; 
  int ui_menu_width = screenWidth - 2 * (left_offset) - checkboard_size;
  int ui_menu_height = screenHeight - 2 * (down_offset) - pixels_offset;

  MenuStyle menu_style(
  ui_menu_width, ui_menu_height,
  menu_ui_start_x, menu_ui_start_y,
  pixels_offset, checkboard_texture);


  GuiSetStyle(DEFAULT, TEXT_PADDING, 0);
  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      //DrawTexture(canvas.texture, 0, 0, WHITE);
      //DrawText("Szachy", screenWidth / 2, screenHeight / 2, 20, BLACK);
      DrawTextureRec(
        checkboard_texture.texture, 
        Rectangle{0, 0, (float)checkboard_texture.texture.width, (float)-checkboard_texture.texture.height },
        Vector2{0, 0}, 
        WHITE
      );
      //ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void draw_frame(int width, int height, int size, int outer_size, RenderTexture2D canvas, struct Color color, struct Color outer_Color)
{
  BeginTextureMode(canvas);
    DrawRectangle(outer_size, outer_size, width - outer_size * 2, size, color);
    DrawRectangle(outer_size, height - outer_size - size, width - outer_size * 2, size, color);
    DrawRectangle(outer_size, outer_size, size, height - outer_size * 2, color);
    DrawRectangle(width - outer_size - size, outer_size, size, height - outer_size * 2, color);

    DrawRectangle(0, 0, width - outer_size, outer_size, outer_Color); //outer
    DrawRectangle(0, height - outer_size, width, outer_size, outer_Color);
    DrawRectangle(0, 0, outer_size, height, outer_Color);
    DrawRectangle(width - outer_size, 0, outer_size, height, outer_Color);
  EndTextureMode();
}
std::pair<int, int> make_checkboard(int width, int height, int left_offset, int
  down_offset, int font_size, RenderTexture2D canvas, struct Color white_c, struct Color black_c,
  int checkboard_size)
  {


    if (checkboard_size == -1)
    {
      checkboard_size = 
      height - down_offset * 2 > width - left_offset * 2 ?
      width - left_offset * 2 : height - down_offset * 2; 
    }
    int pixelsLeft = checkboard_size % 8; 
    // checkboard_size -= pixelsLeft;
    left_offset += pixelsLeft / 2;
    down_offset += pixelsLeft / 2;

    int sq_size = checkboard_size / 8;
  
    bool black = false;
  
    int column_nums = 8;
    char row_letter = 97;
  
    BeginTextureMode(canvas);
    for (int x = left_offset; x < checkboard_size; x += sq_size)
    {
      for (int y = down_offset; y < checkboard_size; y += sq_size)
      {   
        DrawRectangle(x , y, sq_size, sq_size, black ? black_c : white_c);
        black = !black;
        
        if (x == left_offset)
        {
          const char* cString = std::to_string(column_nums).c_str();
          DrawText(cString, x + sq_size / 6.5, y + sq_size / 5.5, font_size, black ? black_c : white_c);
          column_nums--;
        }   
        if (y >= sq_size * 7)
        {
          char str[2] = {row_letter, '\0'};
          DrawText(str, x + sq_size / 1.4, y + sq_size / 1.4, font_size, black ? black_c : white_c);
          row_letter++;
        }
      }
      black = !black;
    }

    EndTextureMode();
    //int total_size = checkboard_size + pixelsLeft;
    return {checkboard_size, pixelsLeft};
    // return checkboard_size;
  } 

  //I dont know if there will be need for this it depends on future decisions so better to leave it for now
  //
  // void make_text_on_checkboard(int width, int height, int sq_size, int left_offset, int
  //   down_offset, int font_size, RenderTexture2D canvas, struct Color white_c, struct Color black_c)
  // {
  //   bool black = true;
  //   int column_nums = 8;
  //   char row_letter = 97;

  //   for (int x = left_offset; x < sq_size * 8; x += sq_size)
  //   {
  //     const char* cString = std::to_string(column_nums).c_str();
  //     DrawText(cString, x + sq_size / 6.5, y + sq_size / 5.5, font_size, black ? black_c : white_c);

  //     column_nums--;
  //     black = !black;
  //   }
  //   for (int y = down_offset; y < sq_size * 8; y += sq_size)
  //   {   
  //     char str[2] = {row_letter, '\0'};
  //     DrawText(str, y + sq_size / 1.4, y + sq_size / 1.4, font_size, black ? black_c : white_c);

  //     row_letter++;
  //     black = !black;
  //   }
  // }

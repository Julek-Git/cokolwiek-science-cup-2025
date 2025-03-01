#include "raylib/raylib.h"
#include <string>

void make_checkboard(int width, int height, RenderTexture2D canvas,  int font_size,
  float offset_perc_updown[2],
  float offset_perc_leftright[2], struct Color white_c, struct Color black_c);

int main() {
  const int screenWidth = 1200;
  const int screenHeight = 800;
  
  InitWindow(screenWidth, screenHeight, "Motorola Science Cup - Szachy");
  SetTargetFPS(60);

  RenderTexture2D chess_board = LoadRenderTexture(screenWidth, screenHeight);  

  float updown[2] = {0.05f, 0.05f};
  float leftright[2] = {0.05f, 0.05f};

  make_checkboard(screenWidth, screenHeight, chess_board, 20, updown, leftright, WHITE, BLUE);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      //DrawTexture(canvas.texture, 0, 0, WHITE);
      //DrawText("Szachy", screenWidth / 2, screenHeight / 2, 20, BLACK);
      DrawTextureRec(
        chess_board.texture, 
        Rectangle{0, 0, (float)chess_board.texture.width, (float)-chess_board.texture.height },
        Vector2{0, 0}, 
        WHITE
      );
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
void make_checkboard(int width, int height, RenderTexture2D canvas,  int font_size,
  float offset_perc_updown[2],
  float offset_perc_leftright[2], struct Color white_c, struct Color black_c)
{
  int left_offset = offset_perc_leftright[0] * width;
  int up_offset = offset_perc_updown[0] * height;
  int right_offset = offset_perc_leftright[1] * width;
  int down_offset = offset_perc_updown[1] * height;
  int checkboard_size = 
  height - up_offset - down_offset >= width - left_offset - right_offset 
  ? width - up_offset - down_offset 
  : height - left_offset - right_offset; 
  int sq_size = checkboard_size / 8;

  bool black = false;

  int column_nums = 8;
  char row_letter = 97;

  BeginTextureMode(canvas);
  for (int x = up_offset; x < checkboard_size; x += sq_size)
  {
    for (int y = left_offset; y < checkboard_size; y += sq_size)
    {   
      DrawRectangle(x , y, sq_size, sq_size, black ? black_c : white_c);
      black = !black;
      
      if (x == up_offset)
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
} 

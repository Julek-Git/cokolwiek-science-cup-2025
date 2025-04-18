#define RAYGUI_IMPLEMENTATION
#include <tuple>
#include <optional>
#include "raylib/raylib.h"
#include "raylib/raygui.h"
#include <string>
#include "MenuStyle/MenuStyle.h"
#include "Game/Game.h"
#include "Player/Player.h"
#include "Player/PlayerOffline.h"
#include "Game/ActionsAndDrawingManager.h"
#include "MenuStyle/StyleInfo.h"
// void make_checkboard(int width, int height, RenderTexture2D canvas,  int font_size,
//   float offset_perc_updown[2],
//   float offset_perc_leftright[2], struct Color white_c, struct Color black_c);
struct CheckboardData
{
  int checkboard_size = 0;
  int left_offset = 0;
  int down_offset = 0;
} checkboard_data;


void draw_frame(int width, int height, int size, int inner_size, RenderTexture2D canvas, 
  struct Color color, struct Color innerColor);

std::pair<int, int> make_checkboard(int width, int height, int left_offset, int
    down_offset, int font_size, RenderTexture2D canvas, struct Color white_c, struct Color black_c,
    int checkboard_size = -1);
Game* InitGame(int checkboard_size, int left_offset, int down_offset, 
  StyleInfo* style_info);

std::pair<MenuStyle*, StyleInfo*> 
InitUI(int screenWidth, int screenHeight, RenderTexture2D checkboard_texture,
CheckboardData &checkboard_data);
  
int main() {
  const int screenWidth = 1200;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "Motorola Science Cup - Szachy");
  SetTargetFPS(60);

  RenderTexture2D checkboard_texture = LoadRenderTexture(screenWidth, screenHeight);  
  
  //Init Game
  StyleInfo* style_info;
  MenuStyle* menu_style;
  std::tie(menu_style, style_info) = 
  InitUI(screenWidth, screenHeight, checkboard_texture, checkboard_data);
  
  Game* game = InitGame(checkboard_data.checkboard_size, checkboard_data.left_offset,
     checkboard_data.down_offset, style_info);
  
  //std::cout << game << std::endl;
  while (!WindowShouldClose()) {
      BeginDrawing();
  
        ClearBackground(RAYWHITE);
  
        menu_style->draw_menu();
        menu_style->draw_outgame_menu();


        DrawTextureRec(
          menu_style->get_canvas().texture, 
          Rectangle{0, 0, (float)checkboard_texture.texture.width, (float)-checkboard_texture.texture.height },
          Vector2{0, 0}, 
          WHITE
        );
        
        game->draw_loop();
        
        //game->debug_func();

        menu_style->set_gui_style();
        menu_style->draw_outgame_menu_gui();
  
      EndDrawing();
    }
  game->delete_mem();
  CloseWindow();
  return 0;
}
std::pair<MenuStyle*, StyleInfo*> InitUI(int screenWidth, int screenHeight, 
  RenderTexture2D checkboard_texture, CheckboardData &checkboard_data)
{
  int size = 15;
  int outer_size = 20;

  Color black = {235, 189, 185, 255};
  Color white = {237, 87, 76, 255};

  checkboard_data.left_offset = outer_size + size;
  checkboard_data.down_offset = outer_size + size;
  //make_checkboard(screenWidth, screenHeight, chess_board, 20, updown, leftright, WHITE, BLUE);
  draw_frame(screenWidth, screenHeight, size, outer_size, checkboard_texture, BLACK, BROWN);
  int pixels_offset;
  std::tie(checkboard_data.checkboard_size, pixels_offset) = 
  make_checkboard(screenWidth, screenHeight, checkboard_data.left_offset, checkboard_data.down_offset, 
    20, checkboard_texture, black, white);
  

  StyleInfo* style_info = new StyleInfo(checkboard_data.checkboard_size,
    black, white);


  //UI
  int menu_ui_start_x = checkboard_data.left_offset + checkboard_data.checkboard_size + pixels_offset;
  int menu_ui_start_y = checkboard_data.down_offset + pixels_offset / 2; 
  int ui_menu_width = screenWidth - 2 * (checkboard_data.left_offset) - checkboard_data.checkboard_size - pixels_offset;
  int ui_menu_height = screenHeight - 2 * (checkboard_data.down_offset) - pixels_offset;

  MenuStyle* menu_style = new MenuStyle(
  ui_menu_width, ui_menu_height,
  menu_ui_start_x, menu_ui_start_y,
  pixels_offset, 20, checkboard_texture);

    menu_style->header_text_color = BLACK;
    menu_style->menu_color = ColorFromHSV(332.0f, 1.0f, 0.56f);
    menu_style->border_color = BLACK;
  
  checkboard_data.left_offset += pixels_offset / 2;
  checkboard_data.down_offset += pixels_offset / 2;
  return {menu_style, style_info};
}
Game* InitGame(int checkboard_size, int left_offset, int down_offset, 
  StyleInfo* style_info)
{
  Player* player1 = new PlayerOffline(true, std::chrono::seconds(5), "Siur");
  Player* player2 = new PlayerOffline(false, std::chrono::seconds(2), "Siur2");
  Game* game = new Game(player1, player2);

  ActionsAndDrawingManager* aadm = new ActionsAndDrawingManager(game,
     checkboard_size, left_offset, 
     down_offset,
     "Simple", style_info);
  game->set_aadm(aadm);
  return game;
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
    //! Bug że gdy mamy duży outer_size i size border to szachownica sie mocno pierdoli!
    //Ale i tak takich duzych nie bedzie wiec jest git, naprawic na koncu najwyzej

    if (checkboard_size == -1)
    {
      checkboard_size = 
      height - down_offset * 2 > width - left_offset * 2 ?
      width - left_offset * 2 : height - down_offset * 2; 
    }
    int pixelsLeft = checkboard_size % 8; 
    checkboard_size -= pixelsLeft;
    left_offset += pixelsLeft / 2;
    down_offset += pixelsLeft / 2;

    int sq_size = checkboard_size / 8;
  
    bool black = false;
  
    int column_nums = 8;
    char row_letter = 97;
  
    BeginTextureMode(canvas);
    for (int x = left_offset; x < checkboard_size + left_offset; x += sq_size)
    {
      for (int y = down_offset; y < checkboard_size + down_offset; y += sq_size)
      {
        DrawRectangle(x , y, sq_size, sq_size, black ? black_c : white_c);
        black = !black; 
        if (x == left_offset)
        {
          const char* cString = std::to_string(column_nums).c_str();
          DrawText(cString, x + sq_size / 6.5, y + sq_size / 5.5, font_size, black ? black_c : white_c);
          column_nums--;
        }   
        if (y >= sq_size * 8)
        {
          char str[2] = {row_letter, '\0'};
          DrawText(str, x + sq_size / 1.4, y + sq_size / 1.4, font_size, black ? black_c : white_c);
          row_letter++;
        }
      }
      black = !black; 
    }

    EndTextureMode();

    return {checkboard_size, pixelsLeft};
  } 
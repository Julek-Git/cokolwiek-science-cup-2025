#ifndef MENUSTYLE_H
#define MENUSTYLE_H

#include <raylib/raylib.h>

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
    int header_border_marginLR;
    int margin_top_header_text;
    RenderTexture2D canvas;
    int p_x;
    int p_y;
    int menu_width;
    int menu_height;

    int mode_srcl_in = 0;
    bool usrnm1_edit = false;
    bool usrnm2_edit = false;
    bool ip_edit = false;
    bool ip_port_edit = false;
    const int usrnm_size = 20;

  public:
    MenuStyle
    (
      int width, int height, 
      int x, int y, 
      int pixels_offset,
      int font_size,
      RenderTexture2D canvas
    );
    void set_gui_style();
    void draw_menu();
    void draw_ingame_menu();
    void draw_ingame_menu_gui();
    void draw_outgame_menu();
    void draw_outgame_menu_gui();
    void draw_gamestat_menu();
    void draw_gamestat_menu_gui();
    void settings_window();
    void draw_settings();
    void draw_settings_gui();
    RenderTexture2D get_canvas();

    Color menu_color;
    bool same_border_style;
    Color header_text_color;
    Color header_border_color;
    Color border_color;
    Color timer_background_color;//
    Color timer_text_color;//

    Color ui_background = {200, 200, 200, 30};
    Color ui_background2 = {142, 0, 66, 255};//kolor menu
    Color ui_background3 = {250, 200, 200, 255};
    Color ui_text = BLACK;
    Color ui_text_highlight = GREEN;

    bool button_giveup_pressed = false;
    bool button_draw_pressed = false;
    bool button_undo_pressed = false;
    bool button_set_pressed = false;
    bool button_play_pressed = false;
    bool button_quit_pressed = false;
    bool button_game_pressed = false;
    int mode_act = 0;
    RenderTexture2D texture;
    //const int usrnm_size = 20;
    char usrnm1[20] = "User1";
    char usrnm2[20] = "User2";
    char ip[15] = "192.168.1.1";
    int ip_port = 37777;
    char * Time1 = "00:00";
    char * Time2 = "00:00";
    bool moving1 = true;
    bool win1 = true;
    bool end_draw = false;
};

#endif  // MenuStyle_h
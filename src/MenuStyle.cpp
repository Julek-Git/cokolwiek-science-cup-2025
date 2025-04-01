#include "MenuStyle/MenuStyle.h"
#include <raylib/raylib.h>
#define RAIGUI_IMPLEMENTATION
#include <raylib/raygui.h>
#include <string>
#include <regex>

MenuStyle::MenuStyle(
  int width, int height, 
  int x, int y, int pixels_offset,
  int font_size,
  RenderTexture2D canvas)
{
  this->canvas = canvas;
  this->width = width;
  this->height = height;
  this->pixels_offset = pixels_offset;
  this->x = x;
  this->y = y; 
  this->font_size = font_size;
  /*
  this->button_draw_pressed = button_draw_pressed;
  this->button_game_pressed = button_game_pressed;
  this->button_giveup_pressed = button_giveup_pressed;
  this->button_play_pressed = button_play_pressed;
  this->button_quit_pressed = button_quit_pressed;
  this->button_set_pressed= button_set_pressed;
  this->button_undo_pressed = button_undo_pressed;
  this->ui_background = ui_background;
  this->ui_background2 = ui_background2;
  this->ui_background3 = ui_background3;
  this->ui_text = ui_text;
  this->ui_text_highlight = ui_text_highlight;
  this->mode_act = mode_act;
  this->usrnm1 = usrnm1;
  this->usrnm2 = usrnm2;
  this->ip = ip;
  this->ip_port = ip_port;
  this->Time1 = Time1;
  this->Time2 = Time2;
  this->moving1 = moving1;
  this->win1 = win1;
  this->end_draw = end_draw;

  this->usrnm1_edit = usrnm1_edit;
  this->usrnm2_edit = usrnm2_edit;
  this->ip_edit = ip_edit;
  this->ip_port_edit = ip_port_edit;
  this->mode_srcl_in = mode_srcl_in;
*/

  left_border_size = 0.03 * width;
  this->width = width - left_border_size - pixels_offset;

  header_border_thickness = 0.005 * height;
  header_border_marginLR = 0.01 * width;
  margin_top_header_text = 0.03 * width;
}
RenderTexture2D MenuStyle::get_canvas() { return canvas; }

void MenuStyle::draw_menu()
{
  BeginTextureMode(canvas);

  int c_x = x;
  int c_y = y;
  
  DrawRectangle(x, y, left_border_size, height, BLACK); 
  c_x += left_border_size + pixels_offset / 2;
  DrawRectangle(c_x, c_y, width, height, menu_color);
    //canvas.texture.
  
  menu_width = width -  header_border_marginLR * 2;

  //header
  DrawRectangle(c_x + header_border_marginLR , 
    c_y + margin_top_header_text, menu_width
    , header_border_thickness, BLACK); //border top

  DrawText("SZACHY", c_x + width / 2 - font_size * 1.8f, c_y + 
    margin_top_header_text * 2, font_size, header_text_color);

  DrawRectangle(c_x +  header_border_marginLR, 
    c_y + margin_top_header_text * 3 + font_size * 0.8, menu_width,
     header_border_thickness, BLACK);

  ////////////////////////////
  //////////////////////////// TIME
  ////////////////////////////
  
  menu_height = height - 2 * margin_top_header_text - font_size - 5*header_border_marginLR;
  p_x = c_x + header_border_marginLR;
  p_y = c_y + margin_top_header_text * 3 + font_size * 0.8 + header_border_thickness + header_border_marginLR;
  
  EndTextureMode(); 
}

///KOLORY I ZMIENNE///////////////////////

Color ui_background = {200, 200, 200, 30};
Color ui_background2 = {142, 0, 66, 255};//kolor menu
Color ui_background3 = {250, 200, 200, 255};
Color ui_text = BLACK;
Color ui_text_highlight = GREEN;
const int usrnm_size = 20;
bool button_giveup_pressed = false;
bool button_draw_pressed = false;
bool button_undo_pressed = false;
bool button_set_pressed = false;
bool button_play_pressed = false;
bool button_quit_pressed = false;
bool button_game_pressed = false;
int mode_srcl_in = 0;
int mode_act = 0;
bool usrnm1_edit = false;
char usrnm1[usrnm_size +1] = "User1";
bool usrnm2_edit = false;
char usrnm2[usrnm_size +1] = "User2";
bool ip_edit = false;
char ip[16] = "192.168.1.1";
bool ip_port_edit = false;
int ip_port = 5689;
char * Time1 = "00:00";
char * Time2 = "00:00";
bool moving1 = true;
bool win1 = true;
bool end_draw = false;
std::regex ip_pat(
  "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}"
  "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
);

void MenuStyle::set_gui_style(){
  GuiSetStyle(DEFAULT, TEXT_SIZE, font_size);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(ui_text));
  GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, ColorToInt(ui_text));
  GuiSetStyle(DEFAULT, TEXT_COLOR_PRESSED, ColorToInt(ui_text));
  GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(ui_background2));
  GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(ui_background));
  GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, ColorToInt(ui_background3));
  GuiSetStyle(DEFAULT, BASE_COLOR_PRESSED, ColorToInt(ui_background2));
  GuiSetStyle(DEFAULT, BASE_COLOR_DISABLED, ColorToInt(GRAY));
  GuiSetStyle(DEFAULT, BORDER_WIDTH, 2);
  GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(ui_background2));
  GuiSetStyle(DEFAULT, BORDER_COLOR_FOCUSED, ColorToInt(ui_background3));
  GuiSetStyle(DEFAULT, BORDER_COLOR_PRESSED, ColorToInt(ui_background));
  GuiSetStyle(DEFAULT, BORDER_COLOR_DISABLED, ColorToInt(GRAY));
}
void MenuStyle::draw_outgame_menu()
{
  BeginTextureMode(canvas);
  int c_x = p_x;
  int c_y = p_y;


  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.75 - header_border_marginLR, ui_background);
  DrawText("Wybierz tryb gry:" , c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, ui_text);


  c_y += menu_height * 0.75;
    //Dolne menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.25, ui_background);
  //Dolne menu - ramki
  DrawRectangle(c_x + header_border_marginLR, c_y + header_border_marginLR,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2, c_y + header_border_marginLR,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + header_border_marginLR, c_y + 0.5*header_border_marginLR + menu_height * 0.125,
    menu_width - 2*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);

  //Dolne menu - środki
  /*
  DrawRectangle(c_x + header_border_marginLR + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width -2*header_border_thickness -2*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness,
    ui_background2);
*/
  EndTextureMode();
 
  }


void MenuStyle::draw_outgame_menu_gui(){
  int c_x = p_x;
  int c_y = p_y;

  GuiListView((Rectangle){c_x + header_border_marginLR, c_y + 2*header_border_marginLR + font_size, 
    menu_width-2*header_border_marginLR, font_size*8},
    "Gracz kontra Gracz;Gracz kontra komputer;Gracz kontra Arcymistrz;Gracz kontra Gracz w sieci"
    , &mode_srcl_in, &mode_act);

//Gracz 1
  DrawText("Podaj swoje imie:", c_x + header_border_marginLR, c_y + 4*header_border_marginLR + 9*font_size, font_size, ui_text);
  if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 5*header_border_marginLR + 10*font_size,
    menu_width-2*header_border_marginLR, font_size+2*header_border_marginLR}, usrnm1, usrnm_size, usrnm1_edit))
    usrnm1_edit =!usrnm1_edit;
//Gracz2 (opcjonalny)
/*
  if (mode_act == 0 || mode_act == 3){
    DrawText("Podaj imie przeciwnika:", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 11*font_size, font_size, BLACK);
    if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 10*header_border_marginLR + 12*font_size,
      menu_width-2*header_border_marginLR, font_size+2*header_border_marginLR}, usrnm2, usrnm_size, usrnm2_edit))
      usrnm2_edit =!usrnm2_edit;
  }
  if(mode_act == 3){
    DrawText("Podaj IP i port", c_x + header_border_marginLR, c_y + 14*header_border_marginLR + 13*font_size, font_size, BLACK);
    if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 15*header_border_marginLR + 14*font_size,
      menu_width*0.7-header_border_marginLR, font_size+2*header_border_marginLR}, ip, 15, ip_edit))
      ip_edit =!ip_edit;
    if (GuiValueBox((Rectangle){c_x + 0*header_border_marginLR + menu_width*0.7, c_y + 15*header_border_marginLR + 14*font_size,
      menu_width*0.3-header_border_marginLR, font_size+2*header_border_marginLR}, "", &ip_port, 1, 99999, ip_port_edit))
      ip_port_edit =!ip_port_edit;
  }*/

  switch (mode_act){
    case 0:
      DrawText("Podaj imie przeciwnika:", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 11*font_size, font_size, ui_text);
      if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 10*header_border_marginLR + 12*font_size,
        menu_width-2*header_border_marginLR, font_size+2*header_border_marginLR}, usrnm2, usrnm_size, usrnm2_edit))
        usrnm2_edit =!usrnm2_edit;
      DrawText("Dwóch graczy gra na tym", c_x + header_border_marginLR, c_y + 14*header_border_marginLR + 13*font_size, font_size, ui_text);
      DrawText("komputerze.", c_x + header_border_marginLR, c_y + 14*header_border_marginLR + 14*font_size, font_size, ui_text);
      //GuiLabel((Rectangle){c_x + header_border_marginLR, c_y + 14*header_border_marginLR, menu_width-2*header_border_marginLR, 200}, "Dwóch graczy gra na tym komputerze");
      break;
    case 1:
      DrawText("Grasz z komputerem, który uzywa", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 11*font_size, font_size, ui_text);
      DrawText("zaprogramowanych strategii gry.", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 12*font_size, font_size, ui_text);
      break;
    case 2:
      DrawText("Grasz z komputerem, który laczy", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 11*font_size, font_size, ui_text);
      DrawText("sie z baza ruchów szachowych", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 12*font_size, font_size, ui_text);
      DrawText("mistrzów i na tej podstawie", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 13*font_size, font_size, ui_text);
      DrawText("podejmuje decyzje.", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 14*font_size, font_size, ui_text);
      break;
    case 3:
      DrawText("Podaj imie przeciwnika:", c_x + header_border_marginLR, c_y + 9*header_border_marginLR + 11*font_size, font_size, ui_text);
      if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 10*header_border_marginLR + 12*font_size,
        menu_width-2*header_border_marginLR, font_size+2*header_border_marginLR}, usrnm2, usrnm_size, usrnm2_edit))
        usrnm2_edit =!usrnm2_edit;
      DrawText("Podaj IP i port", c_x + header_border_marginLR, c_y + 14*header_border_marginLR + 13*font_size, font_size, ui_text);
      if (GuiTextBox((Rectangle){c_x + header_border_marginLR, c_y + 15*header_border_marginLR + 14*font_size,
        menu_width*0.7-header_border_marginLR, font_size+2*header_border_marginLR}, ip, 15, ip_edit)){
        ip_edit =!ip_edit;
        if (std::regex_match(ip, ip_pat))
          *ip = (char) "192.168.1.1";
      }
        
      if (GuiValueBox((Rectangle){c_x + 0*header_border_marginLR + menu_width*0.7, c_y + 15*header_border_marginLR + 14*font_size,
        menu_width*0.3-header_border_marginLR, font_size+2*header_border_marginLR}, "", &ip_port, 1025, 99999, ip_port_edit))
        ip_port_edit =!ip_port_edit;
      DrawText("Laczysz sie z innym komputerem", c_x + header_border_marginLR, c_y + 18*header_border_marginLR + 15*font_size, font_size, ui_text);
      DrawText("w sieci lokalnej", c_x + header_border_marginLR, c_y + 18*header_border_marginLR + 16*font_size, font_size, ui_text);
      break;
  }



  c_y += 0.75*menu_height;



  button_play_pressed = GuiButton((Rectangle){c_x + header_border_marginLR + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness}, "Graj!");
  button_quit_pressed = GuiButton((Rectangle){c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness}, "Wyjdz");
  button_set_pressed = GuiButton((Rectangle){c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width -2*header_border_thickness -2*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness}, "Ustawnienia");

}

/************************************************************************************************************************************************ */
void MenuStyle::draw_ingame_menu()
{
  BeginTextureMode(canvas);
  
  int p_x = x;
  int p_y = y;
  int c_x = p_x;
  int c_y = p_y;

//ZMIENNE





  Color usr1_c = ui_text;
  Color usr2_c = ui_text;
  if (moving1)
    usr1_c = GREEN;
  else
    usr2_c = GREEN;

  //1 menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.375 - header_border_marginLR, ui_background);
  DrawText(usrnm1, c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, usr1_c);
  DrawText(Time1, c_x + header_border_marginLR + menu_width*0.8, c_y + header_border_marginLR, font_size, usr1_c);
  DrawText("Zbite figury:", c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text);
  //Kursor do rysowania figur: c_y + 5*header_border_marginLR + 2*font_size

  c_y += menu_height * 0.375;
  //2 menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.375 - header_border_marginLR, ui_background);
  DrawText(usrnm2, c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, usr2_c);
  DrawText(Time2, c_x + header_border_marginLR + menu_width*0.8, c_y + header_border_marginLR, font_size, usr2_c);
  DrawText("Zbite figury:", c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text);
  //Kursor do rysowania figur: c_y + 5*header_border_marginLR + 2*font_size

  c_y += menu_height * 0.375;

  //Dolne menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.25, ui_background);
  //Dolne menu - ramki
  DrawRectangle(c_x + header_border_marginLR, c_y + header_border_marginLR,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2, c_y + header_border_marginLR,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + header_border_marginLR, c_y + 0.5*header_border_marginLR + menu_height * 0.125,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2, c_y + 0.5*header_border_marginLR + menu_height * 0.125,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);

  //Dolne menu - środki
/*
  DrawRectangle(c_x + header_border_marginLR + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness,
    ui_background2);
*/
  EndTextureMode();
  
}

void MenuStyle::draw_ingame_menu_gui(){
  int c_x = p_x;
  int c_y = p_y;


  c_y += 0.375*menu_height;


  c_y += 0.375*menu_height;

  button_giveup_pressed = GuiButton((Rectangle){c_x + header_border_marginLR + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness}, "Poddaje sie");
  button_draw_pressed = GuiButton((Rectangle){c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + header_border_marginLR + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR - 2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR - 2*header_border_thickness}, "Remis");
  button_undo_pressed = GuiButton((Rectangle){c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness}, "Cofnij");
  button_set_pressed = GuiButton((Rectangle){c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness}, "Ustawnienia");

}

/*************************************************************************************************************************** */
void MenuStyle::draw_gamestat_menu()
{
  BeginTextureMode(canvas);
  int c_x = p_x;
  int c_y = p_y;

//ZMIENNE użyte
/*
  char * Time1 = "00:00";
  char * Time2 = "00:00";
  bool win1 = true;*/
  //usrnm1
  //usrnm2
  //ui_background
  //ui_background2

  Color usr1_c = ui_text;
  Color usr2_c = ui_text;
  if (end_draw){
    usr1_c = ui_text_highlight;
    usr2_c = ui_text_highlight;
  }else{
    if (win1)
      usr1_c = ui_text_highlight;
    else
      usr2_c = ui_text_highlight;
    }
  //1 menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.375 - header_border_marginLR, ui_background);
  DrawText(usrnm1, c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, usr1_c);
  DrawText(Time1, c_x + header_border_marginLR + menu_width*0.8, c_y + header_border_marginLR, font_size, usr1_c);
  DrawText("Zbite figury:", c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text);
  //Kursor do rysowania figur: c_y + 5*header_border_marginLR + 2*font_size

  c_y += menu_height * 0.375;
  //2 menu
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.375 - header_border_marginLR, ui_background);
  DrawText(usrnm2, c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, usr2_c);
  DrawText(Time2, c_x + header_border_marginLR + menu_width*0.8, c_y + header_border_marginLR, font_size, usr2_c);
  DrawText("Zbite figury:", c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text);
  //Kursor do rysowania figur: c_y + 5*header_border_marginLR + 2*font_size

  c_y += menu_height * 0.375;
  DrawRectangle(c_x, c_y, menu_width, menu_height * 0.125 - 2*header_border_marginLR, ui_background);
  if (end_draw){
    DrawText("Remis!",c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, ui_text);
  }else{
    DrawText("Wygrana:",c_x + header_border_marginLR, c_y + header_border_marginLR, font_size, ui_text);
    if (win1)
      DrawText(usrnm1, c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text_highlight);
    else
      DrawText(usrnm2, c_x + header_border_marginLR, c_y + 3*header_border_marginLR + font_size, font_size, ui_text_highlight);
  }
  //Dolne menu
  DrawRectangle(c_x, c_y + menu_height*0.125 -header_border_marginLR, menu_width, menu_height * 0.125 + header_border_marginLR, ui_background);
  //Dolne menu - ramki

  DrawRectangle(c_x + header_border_marginLR, c_y + 0.5*header_border_marginLR + menu_height * 0.125,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2, c_y + 0.5*header_border_marginLR + menu_height * 0.125,
    menu_width/2 - 1.5*header_border_marginLR, menu_height * 0.125 - 1.5*header_border_marginLR,
    BLACK);

  //Dolne menu - środki
/*
  DrawRectangle(c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness,
    ui_background2);
  DrawRectangle(c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
    menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness,
    ui_background2);
*/

  EndTextureMode();
  }

  void MenuStyle::draw_gamestat_menu_gui(){
    int c_x = p_x;
    int c_y = p_y + 0.75*menu_height;

    button_game_pressed = GuiButton((Rectangle){c_x + header_border_marginLR + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
      menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness}, "Nowa gra");
    button_quit_pressed = GuiButton((Rectangle){c_x + 0.5*header_border_marginLR + menu_width/2 + header_border_thickness, c_y + 0.5*header_border_marginLR + menu_height * 0.125 + header_border_thickness,
      menu_width/2 - 1.5*header_border_marginLR -2*header_border_thickness, menu_height * 0.125 - 1.5*header_border_marginLR -2*header_border_thickness}, "Zakoncz");
  }


  const int menuScreenWidth = 600;
  const int menuScreenHeight = 400;

  void MenuStyle::settings_window(){
      texture = 
     LoadRenderTexture(menuScreenWidth, menuScreenHeight);


    InitWindow(menuScreenWidth, menuScreenHeight, "Ustawienia");
    SetTargetFPS(60);
    draw_settings();
    while(!WindowShouldClose()){
      BeginDrawing();
      //ClearBackground(GetColor(GuiSetStyle(DEFAULT, BACKGROUND_COLOR)));
      ClearBackground(WHITE);
      
            
      DrawTextureRec(
        texture.texture, 
        Rectangle{0, 0, (float)texture.texture.width, (float)texture.texture.height },
        Vector2{0, 0}, 
        WHITE
      );
      
      draw_settings_gui();
      EndDrawing();
    }
    UnloadTexture(texture.texture);
    
    

  }


  int tabsize = 150;
  short int currtab = 0;
  void MenuStyle::draw_settings(){
    BeginTextureMode(texture);
    int c_x = menuScreenWidth/2;
    int c_y = menuScreenHeight/2;
    DrawRectangle(c_x, c_y, menuScreenWidth*2, menuScreenHeight*2, ui_background2);
    
    c_x += header_border_marginLR;
    c_y += header_border_marginLR;
    DrawRectangle(c_x-header_border_thickness, c_y-header_border_thickness, 
      menuScreenWidth + 2*header_border_thickness, menuScreenHeight + 2*header_border_thickness, BLACK);
    DrawRectangle(c_x, c_y, menuScreenWidth, menuScreenHeight, ui_background2);

    DrawRectangle(c_x, c_y, tabsize, font_size + 2*header_border_marginLR + 2*header_border_thickness, BLACK);
    if (mode_act == 3)
      DrawRectangle(c_x + tabsize + header_border_marginLR, c_y, tabsize, font_size + 2*header_border_marginLR + 2*header_border_thickness, BLACK);
    
    c_y += font_size + 3*header_border_marginLR;
    //c_x += 0;
    DrawRectangle(c_x, c_y, menuScreenWidth - 2*header_border_marginLR, menuScreenHeight - font_size - 5*header_border_marginLR, BLACK);

    EndTextureMode();


  }

  int style = 0;
  bool style_dropdown_edit = false;
  char my_ip[16] = "192.168.1.100";
  int ping = 0;
  int resp_time = 1;

  void MenuStyle::draw_settings_gui(){
    int c_x = menuScreenWidth/2;
    int c_y = menuScreenHeight/2;
    
    c_x += header_border_marginLR;
    c_y += header_border_marginLR;

    if (GuiButton((Rectangle){c_x + header_border_marginLR, c_y + header_border_marginLR, tabsize - 2*header_border_marginLR, font_size + 2*header_border_marginLR}, "Styl"))
      currtab = 0;
    if (mode_act == 3)
      if (GuiButton((Rectangle){c_x + 2*header_border_marginLR + tabsize,
        c_y + header_border_marginLR, tabsize - 2*header_border_marginLR, font_size + 2*header_border_marginLR}, "Siec"))
        currtab = 1;
    c_y += font_size + 4*header_border_marginLR;
    c_x += header_border_marginLR;
    switch (currtab){
      case 0:
        DrawText("Wybierz styl figur", c_x, c_y, font_size, ui_text);
        if (style_dropdown_edit) 
          GuiLock();
        if(GuiDropdownBox((Rectangle){c_x, c_y + font_size, menuScreenWidth*0.7, font_size + 2*header_border_marginLR}, "Zwykle;Realistyczne;Proste", &style, style_dropdown_edit));
          style_dropdown_edit = !style_dropdown_edit;
        GuiUnlock();


        break;
      case 1:
        DrawText("Twoje IP", c_x ,c_y, font_size, ui_text);
        DrawText(my_ip, c_x ,c_y + 250, font_size, ui_text);
        DrawText("IP przeciwnika", c_x ,c_y + font_size + header_border_marginLR, font_size, ui_text);
        DrawText(ip, c_x + 250 ,c_y + font_size + header_border_marginLR , font_size, ui_text);
        DrawText("Port", c_x ,c_y + 2*font_size +2*header_border_marginLR, font_size, ui_text);
        DrawText(std::to_string((long)ip_port).c_str(), c_x + 250 ,c_y + 2*font_size +2*header_border_marginLR, font_size, ui_text);
        DrawText("Ping", c_x ,c_y + 3*font_size +3*header_border_marginLR, font_size, ui_text);
        DrawText(std::to_string((long)ping).c_str(), c_x + 250 ,c_y + 3*font_size +3*header_border_marginLR, font_size, ui_text);
        DrawText("Czas odpowiedzi", c_x ,c_y + 4*font_size +4*header_border_marginLR, font_size, ui_text);
        DrawText(std::to_string((long)resp_time).c_str(), c_x + 250, c_y + 4*font_size +4*header_border_marginLR , font_size, ui_text);
      break;
    }
  }


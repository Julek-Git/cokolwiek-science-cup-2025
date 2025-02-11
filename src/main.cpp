#include "raylib/raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Motorola Science Cup - Szachy");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Szachy", screenWidth / 2, screenHeight / 2, 20, BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
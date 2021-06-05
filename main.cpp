#include "raylib.h"

const int width = 800, height = 800;

int main()
{
    InitWindow(width, height, "snake game - raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}
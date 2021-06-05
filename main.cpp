#include "raylib.h"

const int width = 800, height = 800;
Vector2 center = {(float)width/2, (float)height/2};
Vector2 snake[200] = {}, tempSnake[200] = {};
int snakeLength = 0;


void LoadSnake()
{
    // initialize snake head
    snake[0] = center;
    tempSnake[0] = center;
    snakeLength++;
    snake[1] = {snake[snakeLength-1].x-50, snake[snakeLength-1].y};
    tempSnake[1] = {snake[snakeLength-1].x-50, snake[snakeLength-1].y};
    snakeLength++;
}

int main()
{
    InitWindow(width, height, "snake game - raylib");
    SetTargetFPS(60);

    LoadSnake();

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = 0; i < snakeLength; i++)
            {
                if (i == 0)
                    DrawRectangle(snake[i].x-25, snake[i].y-25, 50, 50, BLUE);
                else 
                    DrawRectangleLines(snake[i].x-20, snake[i].y-20, 40, 40, BLUE);
            }
        EndDrawing();
    }

    CloseWindow();
}
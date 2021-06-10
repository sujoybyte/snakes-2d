#include "raylib.h"
#include "math.h"

const int screenWidth = 800, screenHeight = 800;
Vector2 center = {(float) screenWidth / 2, (float) screenHeight / 2};
Vector2 snake[200] = {}, tempSnake[200] = {};
int snakeLength = 0;
Vector2 food = {};
bool foodEaten = false;

void LoadSnake();
void MoveSnake(int stepX, int stepY);
void GrowSnake();
void SpawnFood();

int main()
{
    InitWindow(screenWidth, screenHeight, "snake game - raylib");
    SetTargetFPS(60);

    LoadSnake();
    SpawnFood();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_RIGHT)) MoveSnake(50, 0);
        else if (IsKeyPressed(KEY_LEFT)) MoveSnake(-50, 0);
        else if (IsKeyPressed(KEY_UP)) MoveSnake(0, -50);
        else if (IsKeyPressed(KEY_DOWN)) MoveSnake(0, 50);

        foodEaten = (snake[0].x == food.x && snake[0].y == food.y);
        if (foodEaten)
        {
            SpawnFood();
            GrowSnake();
        }

        BeginDrawing();
            ClearBackground(BLACK);
            DrawCircle(food.x, food.y, 15, RED);
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

void MoveSnake(int stepX, int stepY)
{
    // move snake by one unit (50 pixels)
    tempSnake[0] = snake[0];
    snake[0].x = snake[0].x + stepX;
    snake[0].y = snake[0].y + stepY;

    for (int j = 1; j < snakeLength; j++)
    {
        tempSnake[j] = snake[j];
        snake[j] = tempSnake[j-1];
    }
}

void GrowSnake()
{
    // grow snake body by one unit (50 pixels)
    int xDiff = 0, yDiff = 0;
    if (snakeLength > 1)
    {
        xDiff = snake[snakeLength-2].x - snake[snakeLength-1].x;
        yDiff = snake[snakeLength-2].y - snake[snakeLength-1].y;
    }
    snake[snakeLength] = {snake[snakeLength-1].x-xDiff, snake[snakeLength-1].y-yDiff};
    snakeLength++;
    foodEaten = false;
}

void SpawnFood()
{
    // spawn food at random locations
    food.x = 50 * (rand() % 13 + 2);
    food.y = 50 * (rand() % 13 + 2);

    if (food.x == center.x && food.y == center.y)
    {
        food.x = 50 * (rand() % 13 + 2);
        food.y = 50 * (rand() % 13 + 2);
    }
}

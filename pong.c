#include "raylib.h"
#include <stdio.h>
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "exec");
    Vector2 ballPosition = {.x = 400, .y = 225};
    Vector2 ballSize = {.x = 15, .y = 15};
    Vector2 paddlePosition = {.x = 15, .y = 30};
    Vector2 paddleSize = {.x = 15, .y = 90};
    Vector2 paddlePosition2 = {.x = 770, .y = 30};
    Vector2 paddleSize2 = {.x = 15, .y = 90};
    Vector2 collumnPosition = {.x = 392.5, .y = 0};
    Vector2 collumnSize = {.x = 7.5, .y = 450};
    float dx = 3.0f;
    float dy = 3.0f;
    float roc1 = 3.0f;
    float roc2 = 3.0f;
    float roc3 = 3.0f;
    float roc4 = 3.0f;
    float scoreL = 0.0f;
    float scoreR = 0.0f;
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        ballPosition.x += dx;
        ballPosition.y += dy;
        if (ballPosition.y >= 435) dy *= -1.0f;
        if (ballPosition.y <= 0) dy *= -1.0;
        if (ballPosition.x <= -15){
            ballPosition.x = 400;
            ballPosition.y = 225;
            dx *= -1.0f;
            dy *= -1.0f;
            scoreL += 1.0f;
        };
        if (ballPosition.x >= 815){
            ballPosition.x = 400;
            ballPosition.y = 225;
            dx *= -1.0f;
            dy *= -1.0f;
            scoreR += 1.0f;
        };
        if (IsKeyDown(KEY_S)) paddlePosition.y += roc1;
        if (paddlePosition.y >= screenHeight - paddleSize.y) roc1 = 0.0f;
        else roc1 = 3.0f;
        if (IsKeyDown(KEY_W)) paddlePosition.y -= roc2;
        if (paddlePosition.y <= 0) roc2 = 0.0f;
        else roc2 = 3.0f;
        if (IsKeyDown(KEY_UP)) paddlePosition2.y -= roc3;
        if (paddlePosition2.y <= 0) roc3 = 0.0f;
        else roc3 = 3.0f;
        if (IsKeyDown(KEY_DOWN)) paddlePosition2.y += roc4;
        if (paddlePosition2.y >= screenHeight - paddleSize.y) roc4 = 0.0f;
        else roc4 = 3.0f;
        if (paddlePosition.x + paddleSize.x >= ballPosition.x){
            if (paddlePosition.y + paddleSize.y <= ballPosition.y) dx *= -1.0f;
            if (ballPosition.y >= paddlePosition.y) dx *= -1.0f;
        }
        if (paddlePosition2.x + paddleSize2.x - 30 <= ballPosition.x){
            if (paddlePosition2.y + paddleSize2.y >= ballPosition.y) dx *= -1.0f;
            if (ballPosition.y <= paddlePosition2.y) dx *= -1.0f;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleV(collumnPosition, collumnSize, GRAY);
        DrawRectangleV(ballPosition, ballSize, RAYWHITE);
        DrawRectangleV(paddlePosition, paddleSize, RAYWHITE);
        DrawRectangleV(paddlePosition2, paddleSize2, RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
/*
** EPITECH PROJECT, 2022
** win_screen.c
** File description:
** win_screen
*/

#include "includes.h"

void screen_loose()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Baby win !",
            GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);
        EndDrawing();
    }
}

void screen_win()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Mom Win !",
            GetScreenWidth() / 2, GetScreenHeight() / 2, 20, GREEN);
        EndDrawing();
    }
}

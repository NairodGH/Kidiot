/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "include.h"

void my_draw_color(char cell, Vector2 pos, Vector2 size_rect)
{
    if (cell == 'E')
        DrawRectangleV(pos, size_rect, GREEN);
    if (cell == '#')
        DrawRectangleV(pos, size_rect, BLACK);
    if (cell == 'C')
        DrawRectangleV(pos, size_rect, DARKGREEN);
    if (cell == 'B')
        DrawRectangleV(pos, size_rect, BLUE);
    if (cell == 'W')
        DrawRectangleV(pos, size_rect, DARKBLUE);
    if (cell == 'F')
        DrawRectangleV(pos, size_rect, DARKGRAY);
    if (cell == 'T')
        DrawRectangleV(pos, size_rect, GRAY);
}

void draw_second_map(char **floor_2, entity_t *players, int wd, int hg)
{
    Vector2 pos_s = {(wd / 2), 0};
    Vector2 size_rect_s =
        {wd / strlen(floor_2[0]) / 2, hg / get_map_size(floor_2)};
    Vector2 new_play_s = {players[0].pos.y * (wd / strlen(floor_2[0]) / 2),
        players[0].pos.x * (hg / get_map_size(floor_2))};

    for (size_t x  = 0; floor_2[x] != NULL; x++) {
        for (size_t y = 0; floor_2[x][y] != '\0'; y++) {
            my_draw_color(floor_2[x][y], pos_s, size_rect_s);
            pos_s.x += wd / strlen(floor_2[x]) / 2;
        }
        pos_s.x = (wd / 2);
        pos_s.y += hg / get_map_size(floor_2);
    }
    if (players[0].floor == 1) {
        new_play_s.x += wd / 2;
        DrawRectangleV(new_play_s, size_rect_s, MAROON);
    }
}

void draw_map(char **floor_1, char **floor_2, entity_t *players)
{
    int hg = GetScreenHeight();
    int wd = GetScreenWidth();
    Vector2 pos = {0, 0};
    Vector2 size_rect = {wd / strlen(floor_1[0]) / 2, hg / get_map_size(floor_1)};
    Vector2 new_play = {players[0].pos.y * (wd / strlen(floor_1[0]) / 2),
        players[0].pos.x * (hg / get_map_size(floor_1))};

    for (size_t x = 0; floor_1[x] != NULL; x++) {
        for (size_t y = 0; floor_1[x][y] != '\0'; y++) {
            my_draw_color(floor_1[x][y], pos, size_rect);
            pos.x += wd / strlen(floor_1[x]) / 2;
        }
        pos.x = 0;
        pos.y += hg / get_map_size(floor_1);
    }
    draw_second_map(floor_2, players, wd, hg);
    if (players[0].floor == 0)
        DrawRectangleV(new_play, size_rect, MAROON);
}

static void get_keys(int *keys)
{
    if (IsKeyPressed(KEY_RIGHT)) keys[0] = 1;
    if (IsKeyPressed(KEY_LEFT)) keys[1] = 1;
    if (IsKeyPressed(KEY_UP)) keys[2] = 1;
    if (IsKeyPressed(KEY_DOWN)) keys[3] = 1;
    if (IsKeyPressed(KEY_RIGHT) && IsKeyPressed(KEY_UP)) keys[4] = 1;
    if (IsKeyPressed(KEY_RIGHT) && IsKeyPressed(KEY_DOWN)) keys[5] = 1;
    if (IsKeyPressed(KEY_LEFT) && IsKeyPressed(KEY_UP)) keys[6] = 1;
    if (IsKeyPressed(KEY_LEFT) && IsKeyPressed(KEY_DOWN)) keys[7] = 1;
    if (IsKeyPressed(KEY_ENTER)) keys[8];
    if (IsKeyPressed(KEY_D)) keys[9] = 1;
    if (IsKeyPressed(KEY_Q)) keys[10] = 1;
    if (IsKeyPressed(KEY_Z)) keys[11] = 1;
    if (IsKeyPressed(KEY_S)) keys[12] = 1;
    if (IsKeyPressed(KEY_D) && IsKeyPressed(KEY_Z)) keys[13] = 1;
    if (IsKeyPressed(KEY_D) && IsKeyPressed(KEY_S)) keys[14] = 1;
    if (IsKeyPressed(KEY_Q) && IsKeyPressed(KEY_Z)) keys[15] = 1;
    if (IsKeyPressed(KEY_Q) && IsKeyPressed(KEY_S)) keys[16] = 1;
    if (IsKeyPressed(KEY_SPACE)) keys[17] = 1;
}

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    char **floor_1 = read_map("map/first_floor.txt");
    char **floor_2 = read_map("map/second_floor.txt");
    entity_t *players = init_entity();
    int keys[18] = {0};
    
    SetTraceLogLevel(LOG_NONE);
    InitWindow(screenWidth, screenHeight, "Kidiot");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        get_keys(keys);
        game_loop(floor_1, floor_2, players, keys);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_map(floor_1, floor_2, players);
        EndDrawing();
        memset(keys, 0, 18);
    }
    free_double_tab(floor_1);
    free_double_tab(floor_2);
    free(players);
    CloseWindow();
    return 0;
}
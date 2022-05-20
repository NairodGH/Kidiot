#include "kidiot.h"

void my_draw_color(char cell, Vector2 pos, Vector2 size_rect)
{
    if (cell == 'E')
        DrawRectangleV(pos, size_rect, GREEN);
    else if (cell == '#')
        DrawRectangleV(pos, size_rect, BLACK);
    else if (cell == 'C')
        DrawRectangleV(pos, size_rect, DARKGREEN);
    else if (cell == 'B')
        DrawRectangleV(pos, size_rect, BLUE);
    else if (cell == 'W')
        DrawRectangleV(pos, size_rect, DARKBLUE);
    else if (cell == 'F')
        DrawRectangleV(pos, size_rect, DARKGRAY);
    else
        DrawRectangleV(pos, size_rect, GRAY);
}

void draw_second_map(char **second_floor, entity_t *players, int wd, int hg)
{
    Vector2 pos_s = {(wd / 2), 0};
    Vector2 size_rect_s =
        {wd / strlen(second_floor[0]) / 2, hg / get_map_size(second_floor)};
    Vector2 new_play_s = {players[0].pos.y * (wd / strlen(second_floor[0]) / 2),
        players[0].pos.x * (hg / get_map_size(second_floor))};

    for (size_t x  = 0; second_floor[x] != NULL; x++) {
        for (size_t y = 0; second_floor[x][y] != '\0'; y++) {
            my_draw_color(second_floor[x][y], pos_s, size_rect_s);
            pos_s.x += wd / strlen(second_floor[x]) / 2;
        }
        pos_s.x = (wd / 2);
        pos_s.y += hg / get_map_size(second_floor);
    }
    if (players[0].floor == 1) {
        new_play_s.x += wd / 2;
        DrawRectangleV(new_play_s, size_rect_s, MAROON);
    }
}

void draw_map(char **first_floor, char **second_floor, entity_t *players)
{
    int hg = GetScreenHeight();
    int wd = GetScreenWidth();
    Vector2 pos = {0, 0};
    Vector2 size_rect = {wd / strlen(first_floor[0]) / 2, hg / get_map_size(first_floor)};
    Vector2 new_play = {players[0].pos.y * (wd / strlen(first_floor[0]) / 2),
        players[0].pos.x * (hg / get_map_size(first_floor))};

    for (size_t x = 0; first_floor[x] != NULL; x++) {
        for (size_t y = 0; first_floor[x][y] != '\0'; y++) {
            my_draw_color(first_floor[x][y], pos, size_rect);
            pos.x += wd / strlen(first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += hg / get_map_size(first_floor);
    }
    draw_second_map(second_floor, players, wd, hg);
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
    char **first_floor = read_map("map/first_floor.txt");
    char **second_floor = read_map("map/second_floor.txt");
    entity_t *players = init_entity();
    int keys[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    SetTraceLogLevel(LOG_NONE);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        get_keys(keys);
        game_loop(first_floor, second_floor, players, keys);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_map(first_floor, second_floor, players);
        EndDrawing();
        keys[0] = 0, keys[1] = 0, keys[2] = 0, keys[3] = 0;
        keys[4] = 0, keys[5] = 0, keys[6] = 0, keys[7] = 0, keys[8] = 0;
        keys[9] = 0, keys[10] = 0, keys[11] = 0, keys[12] = 0;
        keys[13] = 0, keys[14] = 0, keys[15] = 0, keys[16] = 0, keys[17] = 0;
    }
    free_double_tab(first_floor);
    free_double_tab(second_floor);
    free(players);
    CloseWindow();
    return 0;
}
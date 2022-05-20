#include "kidiot.h"

void draw_map(char **first_floor, char **second_floor, entity_t *players)
{
    int hg = GetScreenHeight();
    Vector2 pos = {0, 0};
    Vector2 pos_s = {hg, 0};
    Vector2 size_rect = {hg / 20, hg / 20};
    Vector2 new_play = {players[0].pos.y * hg / 20, players[0].pos.x * hg / 20};

    for (size_t x = 0; first_floor[x] != NULL; x++) {
        for (size_t y = 0; first_floor[x][y] != '\0'; y++) {
            if (first_floor[x][y] == 'E')
                DrawRectangleV(pos, size_rect, GREEN);
            else if (first_floor[x][y] == '#')
                DrawRectangleV(pos, size_rect, BLACK);
            else
                DrawRectangleV(pos, size_rect, BLUE);
            pos.x += hg / 20;
        }
        pos.x = 0;
        pos.y += hg / get_map_size(first_floor);
    }
    for (size_t x  = 0; second_floor[x] != NULL; x++) {
        for (size_t y = 0; second_floor[x][y] != '\0'; y++) {
            if (second_floor[x][y] == 'E')
                DrawRectangleV(pos_s, size_rect, GREEN);
            else if (second_floor[x][y] == '#')
                DrawRectangleV(pos_s, size_rect, BLACK);
            else
                DrawRectangleV(pos_s, size_rect, BLUE);
            pos_s.x += hg / 20;
        }
        pos_s.x = hg;
        pos_s.y += hg / 20;
    }
    if (players[0].floor == 0)
        DrawRectangleV(new_play, size_rect, MAROON);
    else {
        new_play.x += 700;
        DrawRectangleV(new_play, size_rect, MAROON);
    }
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
}

int main(void)
{
    const int screenWidth = 1400;
    const int screenHeight = 700;
    char **first_floor = read_map("map/first_floor.txt");
    char **second_floor = read_map("map/second_floor.txt");
    entity_t *players = init_entity();
    int keys[8] = {0, 0, 0, 0, 0, 0, 0, 0};
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
        keys[0] = 0, keys[1] = 0, keys[2] = 0, keys[3] = 0, keys[4] = 0, keys[5] = 0, keys[6] = 0, keys[7] = 0;
    }
    free_double_tab(first_floor);
    free_double_tab(second_floor);
    free(players);
    CloseWindow();
    return 0;
}
#include "kidiot.h"

void draw_map(char **first_floor, char **second_floor, entity_t *players)
{
    Vector2 pos = {0, 0};
    Vector2 size_rect = {700 / 20, 700 / 20};
    Vector2 new_play = {players[0].pos.x * 700 / 20, players[0].pos.y * 700 / 20};

    for (size_t x  = 0; first_floor[x] != NULL; x++) {
        for (size_t y = 0; first_floor[x][y] != '\0'; y++) {
            DrawRectangleV(pos, size_rect, BLUE);
            pos.y += 700 / 20;
        }
        pos.y = 0;
        pos.x += 700 / 20;
    }
    DrawRectangleV(new_play, size_rect, MAROON);
}

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 700;
    char **first_floor = read_map("map/first_floor.txt");
    char **second_floor = read_map("map/second_floor.txt");
    entity_t *players = init_entity();
    int keys[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) keys[0] = 1;
        if (IsKeyDown(KEY_LEFT)) keys[1] = 1;
        if (IsKeyDown(KEY_UP)) keys[2] = 1;
        if (IsKeyDown(KEY_DOWN)) keys[3] = 1;
        if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP)) keys[4] = 1;
        if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)) keys[5] = 1;
        if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP)) keys[6] = 1;
        if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN)) keys[7] = 1;
        game_loop(first_floor, second_floor, players, keys);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
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
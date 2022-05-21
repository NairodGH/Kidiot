/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
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
        DrawTextureRec(LoadTexture("ressources/misc.png"), (Rectangle){74, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'T')
        DrawTextureRec(LoadTexture("ressources/misc.png"), (Rectangle){0, 0, 73, 57}, pos, RAYWHITE);
}

void draw_second_map(entity_t *play, int wd, int hg)
{
    Vector2 pos_s = {(wd / 2), 0};
    Vector2 size_rect_s =
        {wd / strlen(play->second_floor[0]) / 2, hg / get_map_size(play->second_floor)};
    Vector2 baby_play = {play->baby->pos.y * (wd / strlen(play->second_floor[0]) / 2),
        play->baby->pos.x * (hg / get_map_size(play->second_floor))};
    Vector2 mom_play = {play->mom->pos.y * (wd / strlen(play->second_floor[0]) / 2),
        play->mom->pos.x * (hg / get_map_size(play->second_floor))};

    for (size_t x  = 0; play->second_floor[x] != NULL; x++) {
        for (size_t y = 0; play->second_floor[x][y] != '\0'; y++) {
            my_draw_color(play->second_floor[x][y], pos_s, size_rect_s);
            pos_s.x += wd / strlen(play->second_floor[x]) / 2;
        }
        pos_s.x = (wd / 2);
        pos_s.y += hg / get_map_size(play->second_floor);
    }
    if (play->baby->floor == 1) {
        baby_play.x += wd / 2;
        DrawRectangleV(baby_play, size_rect_s, MAROON);
    }
    if (play->mom->floor == 1) {
        mom_play.x += wd / 2;
        DrawRectangleV(mom_play, size_rect_s, YELLOW);
    }
}

void draw_map(entity_t *play)
{
    int hg = GetScreenHeight();
    int wd = GetScreenWidth();
    Vector2 pos = {0, 0};
    Vector2 size_rect = {wd / strlen(play->first_floor[0]) / 2, hg / get_map_size(play->first_floor)};
    Vector2 baby_play = {play->baby->pos.y * (wd / strlen(play->first_floor[0]) / 2),
        play->baby->pos.x * (hg / get_map_size(play->first_floor))};
    Vector2 mom_play = {play->mom->pos.y * (wd / strlen(play->first_floor[0]) / 2),
        play->mom->pos.x * (hg / get_map_size(play->first_floor))};

    for (size_t x = 0; play->first_floor[x] != NULL; x++) {
        for (size_t y = 0; play->first_floor[x][y] != '\0'; y++) {
            my_draw_color(play->first_floor[x][y], pos, size_rect);
            pos.x += wd / strlen(play->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += hg / get_map_size(play->first_floor);
    }
    draw_second_map(play, wd, hg);
    if (play->baby->floor == 0)
        DrawRectangleV(baby_play, size_rect, MAROON);
    if (play->mom->floor == 0)
        DrawRectangleV(mom_play, size_rect, YELLOW);
}
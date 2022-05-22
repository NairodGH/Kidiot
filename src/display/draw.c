/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

void my_draw_color(char cell, Vector2 pos, Vector2 size_rect, Texture2D textures[4])
{
    if (cell == 'E')
        DrawRectangleV(pos, size_rect, GREEN);
    if (cell == '#')
        DrawRectangleV(pos, size_rect, BLACK);
    if (cell == 'C')
        DrawTextureRec(textures[2], (Rectangle){731, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'B')
        DrawTextureRec(textures[2], (Rectangle){366, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'W')
        DrawTextureRec(textures[2], (Rectangle){585, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'F')
        DrawTextureRec(textures[2], (Rectangle){74, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'T')
        DrawTextureRec(textures[2], (Rectangle){0, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'V')
        DrawTextureRec(textures[2], (Rectangle){439, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'Z')
        DrawTextureRec(textures[2], (Rectangle){804, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'O')
        DrawTextureRec(textures[2], (Rectangle){220, 0, 73, 57}, pos, RAYWHITE);
    if (cell == 'M')
        DrawTextureRec(textures[2], (Rectangle){147, 0, 73, 57}, pos, RAYWHITE);
}

void draw_baby(kidiot_t *kidiot, Vector2 pos)
{
    DrawTextureRec(kidiot->textures[0], (Rectangle){7, 0, 42, 42}, pos, RAYWHITE);
}

void draw_mom(kidiot_t *kidiot, Vector2 pos)
{
    if (kidiot->keys[8])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){15, 4 + (int)GetTime() % 3 * 62, 22, 59}, pos, RAYWHITE);
    DrawTextureRec(kidiot->textures[1], (Rectangle){18, 65, 17, 59}, pos, RAYWHITE);
}

void draw_second_map(kidiot_t *play, int wd, int hg)
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
            my_draw_color(play->second_floor[x][y], pos_s, size_rect_s, play->textures);
            pos_s.x += wd / strlen(play->second_floor[x]) / 2;
        }
        pos_s.x = (wd / 2);
        pos_s.y += hg / get_map_size(play->second_floor);
    }
    if (play->baby->floor == 1) {
        baby_play.x += wd / 2;
        draw_baby(play, baby_play);
    }
    if (play->mom->floor == 1 && play->baby->vacuum->time <= 0) {
        mom_play.x += wd / 2;
        draw_mom(play, mom_play);
    }
}

void draw_map(kidiot_t *play, int hg, int wd)
{
    Vector2 pos = {0, 0};
    Vector2 size_rect = {wd / strlen(play->first_floor[0]) / 2, hg / get_map_size(play->first_floor)};
    Vector2 baby_play = {play->baby->pos.y * (wd / strlen(play->first_floor[0]) / 2),
        play->baby->pos.x * (hg / get_map_size(play->first_floor))};
    Vector2 mom_play = {play->mom->pos.y * (wd / strlen(play->first_floor[0]) / 2),
        play->mom->pos.x * (hg / get_map_size(play->first_floor))};

    for (size_t x = 0; play->first_floor[x] != NULL; x++) {
        for (size_t y = 0; play->first_floor[x][y] != '\0'; y++) {
            my_draw_color(play->first_floor[x][y], pos, size_rect, play->textures);
            pos.x += wd / strlen(play->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += hg / get_map_size(play->first_floor);
    }
    draw_second_map(play, wd, hg);
    if (play->baby->floor == 0)
        draw_baby(play, baby_play);
    if (play->mom->floor == 0 && play->baby->vacuum->time <= 0)
        draw_mom(play, mom_play);
}
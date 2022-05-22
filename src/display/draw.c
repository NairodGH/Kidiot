/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

void my_draw_color(kidiot_t *kidiot, char cell, Vector2 pos, Vector2 size)
{
    if (cell == 'E')
        DrawTextureRec(kidiot->textures[3],
        (Rectangle){0 + (int)(GetTime() * 10) % 5 * 52, 0, 52, 39}, pos, RAYWHITE);
    if (cell == '#')
        DrawTexturePro(kidiot->textures[2], (Rectangle){950, 0, 73, 58},
        (Rectangle){pos.x, pos.y, size.x, size.y}, (Vector2){0, 0}, 0, RAYWHITE);
    if (cell == 'C')
        DrawTextureRec(kidiot->textures[2], (Rectangle){731, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'B')
        DrawTextureRec(kidiot->textures[2], (Rectangle){366, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'W')
        DrawTextureRec(kidiot->textures[2], (Rectangle){585, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'F')
        DrawTextureRec(kidiot->textures[2], (Rectangle){74, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'T')
        DrawTextureRec(kidiot->textures[2], (Rectangle){0, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'V')
        DrawTextureRec(kidiot->textures[2], (Rectangle){439, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'Z')
        DrawTextureRec(kidiot->textures[2], (Rectangle){804, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'O')
        DrawTextureRec(kidiot->textures[2], (Rectangle){220, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'M')
        DrawTextureRec(kidiot->textures[2], (Rectangle){147, 0, 73, 58}, pos, RAYWHITE);
    if (cell == 'S')
        DrawTexturePro(kidiot->textures[2], (Rectangle){1023, 0, 59, 58},
        (Rectangle){pos.x, pos.y, size.x, size.y}, (Vector2){0, 0}, 0, RAYWHITE);
}

void draw_baby(kidiot_t *kidiot, Vector2 pos)
{
    if (kidiot->keys[0])
        return DrawTextureRec(kidiot->textures[0],
        (Rectangle){410, 7 + (int)GetTime() % 3 * 44, 32, 40}, pos, RAYWHITE);
    if (kidiot->keys[1])
        return DrawTextureRec(kidiot->textures[0],
        (Rectangle){140, 7 + (int)GetTime() % 3 * 44, 32, 40}, pos, RAYWHITE);
    if (kidiot->keys[2])
        return DrawTextureRec(kidiot->textures[0],
        (Rectangle){274, 7 + (int)GetTime() % 3 * 44, 32, 40}, pos, RAYWHITE);
    if (kidiot->keys[3])
        return DrawTextureRec(kidiot->textures[0],
        (Rectangle){7, 7 + (int)GetTime() % 3 * 44, 32, 40}, pos, RAYWHITE);
    if (kidiot->keys[4])
        return DrawTextureRec(kidiot->textures[0],
        (Rectangle){7, 280 + (int)GetTime() % 3 * 44, 42, 42}, pos, RAYWHITE);
    DrawTextureRec(kidiot->textures[0], (Rectangle){7, 7, 32, 40}, pos, RAYWHITE);
}

void draw_mom(kidiot_t *kidiot, Vector2 pos)
{
    if (kidiot->keys[5])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){441, 4 + (int)GetTime() % 3 * 62, 28, 60}, pos, RAYWHITE);
    if (kidiot->keys[6])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){156, 4 + (int)GetTime() % 3 * 62, 28, 60}, pos, RAYWHITE);
    if (kidiot->keys[7])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){302, 4 + (int)GetTime() % 3 * 62, 28, 60}, pos, RAYWHITE);
    if (kidiot->keys[8])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){15, 4 + (int)GetTime() % 3 * 62, 28, 60}, pos, RAYWHITE);
    if (kidiot->keys[9])
        return DrawTextureRec(kidiot->textures[1],
        (Rectangle){3, 196 + (int)GetTime() % 3 * 62, 50, 60}, pos, RAYWHITE);
    DrawTextureRec(kidiot->textures[1], (Rectangle){18, 65, 17, 60}, pos, RAYWHITE);
}

void draw_second_map(kidiot_t *kidiot, int width, int height)
{
    Vector2 pos = {(width / 2), 0};
    Vector2 size =
        {width / strlen(kidiot->second_floor[0]) / 2, height / get_map_size(kidiot->second_floor)};
    Vector2 baby = {kidiot->baby->pos.y * (width / strlen(kidiot->second_floor[0]) / 2),
        kidiot->baby->pos.x * (height / get_map_size(kidiot->second_floor))};
    Vector2 mom = {kidiot->mom->pos.y * (width / strlen(kidiot->second_floor[0]) / 2),
        kidiot->mom->pos.x * (height / get_map_size(kidiot->second_floor))};

    for (size_t x  = 0; kidiot->second_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->second_floor[x][y] != '\0'; y++) {
            DrawTexturePro(kidiot->textures[2], (Rectangle){877, 0, 73, 58},
            (Rectangle){pos.x, pos.y, size.x, size.y}, (Vector2){0, 0}, 0, RAYWHITE);
            pos.x += width / strlen(kidiot->second_floor[x]) / 2;
        }
        pos.x = (width / 2);
        pos.y += height / get_map_size(kidiot->second_floor);
    }
    pos.y = 0;
    for (size_t x  = 0; kidiot->second_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->second_floor[x][y] != '\0'; y++) {
            my_draw_color(kidiot, kidiot->second_floor[x][y], pos, size);
            pos.x += width / strlen(kidiot->second_floor[x]) / 2;
        }
        pos.x = (width / 2);
        pos.y += height / get_map_size(kidiot->second_floor);
    }
    if (kidiot->baby->floor == 1) {
        baby.x += width / 2;
        draw_baby(kidiot, baby);
    }
    if (kidiot->mom->floor == 1 && kidiot->baby->vacuum->time <= 0) {
        mom.x += width / 2;
        draw_mom(kidiot, mom);
    }
}

void draw_map(kidiot_t *kidiot, int height, int width)
{
    Vector2 pos = {0, 0};
    Vector2 size = {width / strlen(kidiot->first_floor[0]) / 2, height / get_map_size(kidiot->first_floor)};
    Vector2 baby = {kidiot->baby->pos.y * (width / strlen(kidiot->first_floor[0]) / 2),
        kidiot->baby->pos.x * (height / get_map_size(kidiot->first_floor))};
    Vector2 mom = {kidiot->mom->pos.y * (width / strlen(kidiot->first_floor[0]) / 2),
        kidiot->mom->pos.x * (height / get_map_size(kidiot->first_floor))};
    
    for (size_t x = 0; kidiot->first_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->first_floor[x][y] != '\0'; y++) {
            DrawTexturePro(kidiot->textures[2], (Rectangle){877, 0, 73, 58},
            (Rectangle){pos.x, pos.y, size.x, size.y}, (Vector2){0, 0}, 0, RAYWHITE);
            pos.x += width / strlen(kidiot->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += height / get_map_size(kidiot->first_floor);
    }
    pos.y = 0;
    for (size_t x = 0; kidiot->first_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->first_floor[x][y] != '\0'; y++) {
            my_draw_color(kidiot, kidiot->first_floor[x][y], pos, size);
            pos.x += width / strlen(kidiot->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += height / get_map_size(kidiot->first_floor);
    }
    draw_second_map(kidiot, width, height);
    if (kidiot->baby->floor == 0)
        draw_baby(kidiot, baby);
    if (kidiot->mom->floor == 0 && kidiot->baby->vacuum->time <= 0)
        draw_mom(kidiot, mom);
}
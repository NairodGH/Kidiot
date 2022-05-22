/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

void draw_cactus(kidiot_t *kidiot, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    for (size_t i = 0; kidiot->baby->cactus[i].floor != -1; i++)
        if ((int)kidiot->baby->cactus[i].pos.x == (int)pos.pos.y && (int)kidiot->baby->cactus[i].pos.y == (int)pos.pos.x
            && kidiot->baby->cactus[i].floor == pos.floor) {
            if (kidiot->baby->cactus[i].is_cut) {
                dest.height /= 2;
                dest.y += dest.height;
                DrawTexturePro(kidiot->textures[2], (Rectangle){658, 0, 12, 12}, dest, orig, 0, RAYWHITE);
            }
            else
                DrawTexturePro(kidiot->textures[2], (Rectangle){731, 0, 16, 18}, dest, orig, 0, RAYWHITE);
        }
}

void draw_misc(kidiot_t *kidiot, char cell, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    if (cell == '#')
        DrawTexturePro(kidiot->textures[2], (Rectangle){950, 0, 73, 58}, dest, orig, 0, RAYWHITE);
    if (cell == 'B')
        DrawTexturePro(kidiot->textures[2], (Rectangle){366, 0, 30, 58},
        dest, orig, 0, RAYWHITE);
    if (cell == 'C')
        draw_cactus(kidiot, dest, pos);
    if (cell == 'E')
        DrawTexturePro(kidiot->textures[3], (Rectangle){0 + (int)(GetTime() * 10) % 5 * 104, 0, 107, 87},
        dest, orig, 0, RAYWHITE);
    if (cell == 'F')
        DrawTexturePro(kidiot->textures[2], (Rectangle){74, 0, 28, 48}, dest, orig, 0, RAYWHITE);
    if (cell == 'M') {
        dest.height /= 2;
        DrawTexturePro(kidiot->textures[2], (Rectangle){147, 0, 25, 20}, dest, orig, 0, RAYWHITE);
    }
    if (cell == 'O')
        DrawTexturePro(kidiot->textures[2], (Rectangle){220, 0, 31, 40}, dest, orig, 0, RAYWHITE);
    if (cell == 'S')
        DrawTexturePro(kidiot->textures[2], (Rectangle){1023, 0, 59, 58}, dest, orig, 0, RAYWHITE);
    if (cell == 'T') {
        dest.width *= 3;
        DrawTexturePro(kidiot->textures[2], (Rectangle){0, 0, 73, 39}, dest, orig, 0, RAYWHITE);
    }
    if (cell == 'V')
        DrawTexturePro(kidiot->textures[2], (Rectangle){439, 0, 21, 31}, dest, orig, 0, RAYWHITE);
    if (cell == 'W')
        DrawTexturePro(kidiot->textures[2], (Rectangle){585, 0, 27, 38}, dest, orig, 0, RAYWHITE);
    if (cell == 'Z')
        DrawTexturePro(kidiot->textures[2], (Rectangle){804, 0, 27, 55}, dest, orig, 0, RAYWHITE);
}

void draw_baby(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[0])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){800, 8 + (int)(GetTime() * 10) % 3 * 87, 61, 78}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[1])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){283, 17 + (int)(GetTime() * 10) % 3 * 87, 61, 78}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[2])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){548, 17 + (int)(GetTime() * 10) % 3 * 87, 61, 80}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[3])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){16, 16 + (int)(GetTime() * 10) % 3 * 87, 61, 80}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[4])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){13, 286 + (int)(GetTime() * 10) % 3 * 86, 85, 79}, dest, orig, 0, RAYWHITE);
    DrawTexturePro(kidiot->textures[0], (Rectangle){16, 103, 61, 80}, dest, orig, 0, RAYWHITE);
}

void draw_mom(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[5])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){880, 10 + (int)(GetTime() * 10) % 3 * 124, 52, 116}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[6])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){306, 10 + (int)(GetTime() * 10) % 3 * 124, 52, 116}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[7])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){600, 9 + (int)(GetTime() * 10) % 3 * 124, 40, 116}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[8])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){29, 9 + (int)(GetTime() * 10) % 3 * 124, 43, 116}, dest, orig, 0, RAYWHITE);
    if (kidiot->keys[9])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){5, 392 + (int)(GetTime() * 10) % 3 * 124, 98, 116}, dest, orig, 0, RAYWHITE);
    DrawTexturePro(kidiot->textures[1], (Rectangle){29, 133, 43, 116}, dest, orig, 0, RAYWHITE);
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
            draw_misc(kidiot, kidiot->second_floor[x][y],
            (Rectangle){pos.x, pos.y, size.x, size.y}, (pos_t){(Vector2){x, y}, 1});
            pos.x += width / strlen(kidiot->second_floor[x]) / 2;
        }
        pos.x = (width / 2);
        pos.y += height / get_map_size(kidiot->second_floor);
    }
    if (kidiot->baby->floor == 1) {
        baby.x += width / 2;
        draw_baby(kidiot, (Rectangle){baby.x, baby.y, size.x, size.y});
    }
    if (kidiot->mom->floor == 1 && kidiot->baby->vacuum->time <= 0) {
        mom.x += width / 2;
        draw_mom(kidiot, (Rectangle){mom.x, mom.y, size.x, size.y});
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
            draw_misc(kidiot, kidiot->first_floor[x][y],
            (Rectangle){pos.x, pos.y, size.x, size.y}, (pos_t){(Vector2){x, y}, 0});
            pos.x += width / strlen(kidiot->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += height / get_map_size(kidiot->first_floor);
    }
    draw_second_map(kidiot, width, height);
    if (kidiot->baby->floor == 0)
        draw_baby(kidiot, (Rectangle){baby.x, baby.y, size.x, size.y});
    if (kidiot->mom->floor == 0 && kidiot->baby->vacuum->time <= 0)
        draw_mom(kidiot, (Rectangle){mom.x, mom.y, size.x, size.y});
}
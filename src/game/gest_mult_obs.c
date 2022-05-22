/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

void find_rescue_elec(kidiot_t *kidiot, int x, int y)
{
    size_t i = 0;

    while (kidiot->baby->electric[i].floor != -1) {
        if ((int)kidiot->baby->electric[i].pos.x == y &&
            (int)kidiot->baby->electric[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->electric[i].floor) {
            break;
        }
        i++;
    }
    if (kidiot->baby->electric[i].floor == -1)
        return;
    kidiot->baby->electric[i].is_fixed = true;
}

void find_elec(kidiot_t *kidiot, int x, int y, float time)
{
    size_t i = 0;
    char *buffer = NULL;

    for (i = 0; kidiot->baby->electric[i].floor != -1; i++) {
        if ((int)kidiot->baby->electric[i].pos.x == y &&
            (int)kidiot->baby->electric[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->electric[i].floor) {
            break;
        }
    }
    if (kidiot->baby->electric[i].floor == -1
        || kidiot->baby->electric[i].is_fixed)
        return;
    asprintf(&buffer, "time : %0.1f", kidiot->baby->electric[i].time);
    DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
    free(buffer);
    kidiot->baby->electric[i].time -= time;
    if (kidiot->baby->electric[i].time < 0)
        kidiot->baby->hp -= 100;
}

void find_rescue_cactus(kidiot_t *kidiot, int x, int y)
{
    size_t i = 0;

    while (kidiot->baby->cactus[i].floor != -1) {
        if ((int)kidiot->baby->cactus[i].pos.x == y &&
            (int)kidiot->baby->cactus[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->cactus[i].floor)
            break;
        i++;
    }
    if (kidiot->baby->cactus[i].floor == -1)
        return;
    kidiot->baby->cactus[i].is_cut = true;
}

void find_cactus(kidiot_t *kidiot, int x, int y, float time)
{
    size_t i = 0;

    while (kidiot->baby->cactus[i].floor != -1) {
        if ((int)kidiot->baby->cactus[i].pos.x == y &&
            (int)kidiot->baby->cactus[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->cactus[i].floor)
            break;
        i++;
    }
    if (kidiot->baby->cactus[i].floor == -1 || kidiot->baby->cactus[i].is_cut)
        return;
    if (kidiot->baby->cactus[i].time <= 0) {
        kidiot->baby->hp -= 10;
         kidiot->baby->cactus[i].time = 2;
    }
    kidiot->baby->cactus[i].time -= time;
}

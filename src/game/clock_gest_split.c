/*
** EPITECH PROJECT, 2022
** gest_clock.c
** File description:
** gest_clock
*/

#include "includes.h"

static void gest_clock_buff(char **map, kidiot_t *play, int keys[], float time)
{
    char *buffer = NULL;

    if (keys[4] == 1 &&
        (map[(int)(play->baby->pos.x)][(int)play->baby->pos.y]) == 'V'
        && !play->baby->vacuum->already_use) {
        PlaySound(play->use);
        play->baby->vacuum->already_use = true;
        play->baby->vacuum->time = 3;
        play->mom->pos.x = play->baby->pos.x;
        play->mom->pos.y = play->baby->pos.y;
    } else if (play->baby->vacuum->time > 0) {
        asprintf(&buffer, "time : %0.1f", play->baby->vacuum->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);
        play->baby->vacuum->time -= time;
    }
}

void gest_clock_split(char **map, kidiot_t *play, int keys[], float time)
{
    char *buffer = NULL;

    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'C')
        find_cactus(play, (int)play->baby->pos.x, (int)play->baby->pos.y, time);
    else {
        for (size_t i = 0; play->baby->cactus[i].floor != -1; i++)
            play->baby->cactus[i].time = 2;
    }
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'B'
        && keys[4] == 1)
        play->baby->bathtub->is_open = true;
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'B'
        && play->baby->bathtub->is_open) {
        asprintf(&buffer, "time : %0.1f", play->baby->bathtub->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);
        play->baby->bathtub->time -= time;
    } else
        play->baby->bathtub->time = 4;
    gest_clock_buff(map, play, keys, time);
}
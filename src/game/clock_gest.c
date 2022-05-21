/*
** EPITECH PROJECT, 2022
** gest_clock.c
** File description:
** gest_clock
*/

#include "include.h"

static void check_oven(kidiot_t *players, char **map, float time)
{
    if (players->baby->oven->is_burning == true)
        players->baby->oven->time_burn -= time;
    if (players->baby->oven->time <= 0)
        players->baby->oven->is_burning = true;
    else if (map[(int)players->baby->pos.x][(int)players->baby->pos.y] == 'O')
        players->baby->oven->time -= time;
    else
        players->baby->oven->time = 3;
}

void gest_clock(kidiot_t *players)
{
    char **map =
        players->baby->floor == 0 ? players->first_floor : players->second_floor;
    float time = GetFrameTime();

    if (players->baby->cactus->time > 0)
        players->baby->cactus->time -= time;
    else
        players->baby->cactus->time = 0;
    if (players->baby->fridge->time > 0)
        players->baby->fridge->time -= time;
    else
        players->baby->fridge->time = 0;
    if (map[(int)players->baby->pos.x][(int)players->baby->pos.y] == 'B')
        players->baby->bathtub->time -= time;
    else
        players->baby->bathtub->time = 4;
    if (map[(int)players->baby->pos.x][(int)players->baby->pos.y] == 'E')
        players->baby->electric->time -= time;
    else
        players->baby->electric->time = 5;
    check_oven(players, map, time);
}
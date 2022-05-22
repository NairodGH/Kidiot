/*
** EPITECH PROJECT, 2022
** gest_clock.c
** File description:
** gest_clock
*/

#include "includes.h"

static void check_microwave(kidiot_t *play, char **map, float time)
{
    char *buffer = NULL;

    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'M'
        && play->baby->microwave->is_open && play->baby->microwave->time <= 0)
        play->baby->speed = 0.1;
    else if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'M'
        && play->baby->microwave->is_open) {
        asprintf(&buffer, "time : %0.1f", play->baby->microwave->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);
        play->baby->microwave->time -= time;
    }
    else
        play->baby->microwave->time = 3;
}

static void check_oven(kidiot_t *play, char **map, float time)
{
    char *buffer = NULL;

    if (play->baby->oven->is_burning == true)
        play->baby->oven->time_burn -= time;
    if (play->baby->oven->time <= 0)
        play->baby->oven->is_burning = true;
    else if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'O'
        && play->baby->oven->is_open == true) {
        asprintf(&buffer, "time : %0.1f", play->baby->oven->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);    
        play->baby->oven->time -= time;
    }
    else
        play->baby->oven->time = 3;
    check_microwave(play, map, time);
}

static void check_mom_rescue_split(char **map, kidiot_t *play, int keys[])
{
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'B'
        && keys[9] == 1)
        play->baby->bathtub->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'F'
        && keys[9] == 1)
        play->baby->fridge->is_open = false; 
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'O'
        && keys[9] == 1)
        play->baby->oven->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'M'
        && keys[9] == 1)
        play->baby->microwave->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'C'
        && keys[9] == 1)
        find_rescue_cactus(play, (int)play->mom->pos.x, (int)play->mom->pos.y);
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'E'
        && keys[9] == 1)
        find_rescue_elec(play, (int)play->mom->pos.x, (int)play->mom->pos.y);
}

static void check_mom_rescue(kidiot_t *play, int keys[])
{
    char **map = play->mom->floor == 0 ?
        play->first_floor : play->second_floor;

    if ((int)play->mom->pos.x == (int)play->baby->pos.x && keys[9] == 1
        && (int)play->mom->pos.y == (int)play->baby->pos.y
        && play->baby->floor == play->mom->floor) {
        play->baby->oven->is_burning = false;
        play->baby->speed = 0.05;
    }
    check_mom_rescue_split(map, play, keys);
    if ((int)play->mom->pos.x == play->tp->pos_toilet[0].x &&
        (int)play->mom->pos.y == play->tp->pos_toilet[0].y && keys[9] == 1)
        play->tp->is_open[0] = false;
    if ((int)play->mom->pos.x == play->tp->pos_toilet[1].x &&
        (int)play->mom->pos.y == play->tp->pos_toilet[1].y && keys[9] == 1)
        play->tp->is_open[1] = false;
}

void gest_clock_split(char **map, kidiot_t *play, int keys[], float time)
{
    char *buffer = NULL;

    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'B'
        && play->baby->bathtub->is_open) {
        asprintf(&buffer, "time : %0.1f", play->baby->bathtub->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);
        play->baby->bathtub->time -= time;
    } else
        play->baby->bathtub->time = 4;
    if (keys[4] == 1 &&
        (map[(int)(play->baby->pos.x)][(int)play->baby->pos.y]) == 'V'
        && !play->baby->vacuum->already_use) {
        PlaySound(play->use);
        play->baby->vacuum->already_use = true;
        play->baby->vacuum->time = 3;
    } else if (play->baby->vacuum->time > 0) {
        asprintf(&buffer, "time : %0.1f", play->baby->vacuum->time);
        DrawText(buffer, GetScreenWidth() / 5, 5, 20, LIGHTGRAY);
        free(buffer);
        play->baby->vacuum->time -= time;
    }
}

void gest_clock(kidiot_t *play, int keys[])
{
    char **map = play->baby->floor == 0 ?
        play->first_floor : play->second_floor;
    float time = GetFrameTime();
    char *buffer;

    play->game_time -= time;
    check_mom_rescue(play, keys);
    if (play->baby->fridge->time > 0)
        play->baby->fridge->time -= time;
    else
        play->baby->fridge->time = 0;
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'E')
        find_elec(play, (int)play->baby->pos.x, (int)play->baby->pos.y, time);
    else {
        for (size_t i = 0; play->baby->electric[i].floor != -1; i++)
            play->baby->electric[i].time = 5;
    }
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'C')
        find_cactus(play, (int)play->baby->pos.x, (int)play->baby->pos.y, time);
    else {
        for (size_t i = 0; play->baby->cactus[i].floor != -1; i++)
            play->baby->cactus[i].time = 2;
    }
    gest_clock_split(map, play, keys, time);
    check_oven(play, map, time);
}
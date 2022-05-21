/*
** EPITECH PROJECT, 2022
** move_players.c
** File description:
** move_players
*/

#include "include.h"

static bool move_players_baby_split(char **map, kidiot_t *play, int keys[])
{
    if (keys[4] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x - 1][(int)play->baby->pos.y + 1], play, true))) {
        play->baby->pos.x -= 1, play->baby->pos.y += 1;
        return true;
    }
    if (keys[5] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x + 1][(int)play->baby->pos.y + 1], play, true))) {
        play->baby->pos.x += 1, play->baby->pos.y += 1;
        return true;
    }
    if (keys[6] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x - 1][(int)play->baby->pos.y - 1], play, true))) {
        play->baby->pos.x -= 1, play->baby->pos.y -= 1;
        return true;
    }
    if (keys[7] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x + 1][(int)play->baby->pos.y - 1], play, true))) {
        play->baby->pos.x += 1, play->baby->pos.y -= 1;
        return true;
    }
    return false;
}

void move_players_baby(kidiot_t *play, int keys[])
{
    char **map = NULL;

    if (play->baby->floor == 0)
        map = play->first_floor;
    else
        map = play->second_floor;
    if (move_players_baby_split(map, play, keys))
        return;
    if (keys[0] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x][(int)play->baby->pos.y + 1], play, true)))
        play->baby->pos.y += 1;
    if (keys[1] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x][(int)play->baby->pos.y - 1], play, true)))
        play->baby->pos.y -= 1;
    if (keys[2] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x - 1][(int)play->baby->pos.y], play, true)))
        play->baby->pos.x -= 1;
    if (keys[3] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x + 1][(int)play->baby->pos.y], play, true)))
        play->baby->pos.x += 1;
}

static bool move_players_mom_split(char **map, kidiot_t *play, int keys[])
{
    if (keys[13] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x - 1][(int)play->mom->pos.y + 1], play, false))) {
        play->mom->pos.x -= 1, play->mom->pos.y += 1;
        return true;
    }
    if (keys[14] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x + 1][(int)play->mom->pos.y + 1], play, false))) {
        play->mom->pos.x += 1, play->mom->pos.y += 1;
        return true;
    }
    if (keys[15] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x - 1][(int)play->mom->pos.y - 1], play, false))) {
        play->mom->pos.x -= 1, play->mom->pos.y -= 1;
        return true;
    }
    if (keys[16] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x + 1][(int)play->mom->pos.y - 1], play, false))) {
        play->mom->pos.x += 1, play->mom->pos.y -= 1;
        return true;
    }
    return false;
}

void move_players_mom(kidiot_t *play, int keys[])
{
    char **map = NULL;

    if (play->mom->floor == 0)
        map = play->first_floor;
    else
        map = play->second_floor;
    if (move_players_mom_split(map, play, keys))
        return;
    if (keys[9] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x][(int)play->mom->pos.y + 1], play, false)))
        play->mom->pos.y += 1;
    if (keys[10] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x][(int)play->mom->pos.y - 1], play, false)))
        play->mom->pos.y -= 1;
    if (keys[11] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x - 1][(int)play->mom->pos.y], play, false)))
        play->mom->pos.x -= 1;
    if (keys[12] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x + 1][(int)play->mom->pos.y], play, false)))
        play->mom->pos.x += 1;
}
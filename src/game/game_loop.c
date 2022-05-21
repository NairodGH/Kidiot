/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "include.h"

static bool check_death(char **floor_1, char **floor_2, entity_t *player)
{
    char **map = NULL;

    if (player->baby->floor == 0)
        map = floor_1;
    else
        map = floor_2;
    if (map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'C' ||
        map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'O' ||
        map[(int)player->baby->pos.x][(int)player->baby->pos.y]  == 'F')
        player->baby->hp -= 10;
    if (player->baby->hp <= 0)
        return true;
    return false;
}

bool is_obstacle(char obs, entity_t *play)
{
    if (obs == '#' || obs == 'T' || obs == 'Z')
        return true;
    if (obs == 'W' && play->baby->floor == 0) {
        play->baby->pos.x = 1;
        play->baby->pos.y = 1;
        play->baby->floor = 1;
        return true;
    }
    return false;
}

bool game_loop(char **floor_1, char **floor_2, entity_t *play, int keys[])
{
    move_players_baby(floor_1, floor_2, play, keys);
    move_players_mom(floor_1, floor_2, play, keys);
    if (check_death(floor_1, floor_2, play))
        return true;
    return false;
}
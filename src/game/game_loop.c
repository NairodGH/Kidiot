/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "include.h"

static bool check_death(kidiot_t *player)
{
    char **map = NULL;

    if (player->baby->floor == 0)
        map = player->first_floor;
    else
        map = player->second_floor;
    if (map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'C' ||
        map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'O' ||
        map[(int)player->baby->pos.x][(int)player->baby->pos.y]  == 'F')
        player->baby->hp -= 10;
    if (player->baby->hp <= 0)
        return true;
    return false;
}

bool is_obstacle(char obs, kidiot_t *play, bool baby)
{
    if (obs == '#' || obs == 'T' || obs == 'Z' || obs == '+')
        return true;
    if (obs == 'W' && baby) {
        if (play->baby->floor == 0) {
            play->baby->pos = play->tp->pos_toilet[1];
            play->baby->floor = 1;
        }
        else {
            play->baby->pos = play->tp->pos_toilet[0];
            play->baby->floor = 0;
        }
        return true;
    }
    if (obs == 'S') {
        if (baby) {
            if (play->baby->floor == 0) {
                play->baby->pos = play->tp->pos_stairs[1];
                play->baby->floor = 1;
            }
            else {
                play->baby->pos = play->tp->pos_stairs[0];
                play->baby->floor = 0;
            }
        }
        else {
            if (play->mom->floor == 0) {
                play->mom->pos = play->tp->pos_stairs[1];
                play->mom->floor = 1;
            }
            else {
                play->mom->pos = play->tp->pos_stairs[0];
                play->mom->floor = 0;
            }
        }
        return true;
    }
    return false;
}

void print_keys(int keys[])
{
    for (size_t i = 0; i != 18; i++) {
        printf("i: %d re: %d ", i, keys[i]);
    }
    printf("\n");
}

bool game_loop(kidiot_t *play, int keys[])
{
    move_players_baby(play, keys);
    move_players_mom(play, keys);
    if (check_death(play))
        return true;
    return false;
}
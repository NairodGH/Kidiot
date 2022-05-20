/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "kidiot.h"

static bool check_death(char **first_floor, char **second_floor, entity_t *player)
{
    char **map = NULL;

    if (player->floor == 0)
        map = first_floor;
    else
        map = second_floor;
    if (map[(int)player->pos.x][(int)player->pos.y] == 'C' ||
        map[(int)player->pos.x][(int)player->pos.y] == 'O' ||
        map[(int)player->pos.x][(int)player->pos.y]  == 'F')
        player->hp = player->hp -= 10;
    if (player->hp <= 0)
        return true;
    return false;
}

static bool is_obstacle(char obs, entity_t *play)
{
    if (obs == 'F' || obs == '#' || obs == 'O')
        return true;
    if (obs == 'E' && play->floor == 0) {
        play->pos.x = 1;
        play->pos.y = 1;
        play->floor = 1;
        return true;
    }
    return false;
}

static bool move_players_split(char **map, entity_t play[], int keys[])
{
    if (keys[4] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x - 1][(int)play[0].pos.y + 1], &play[0]))) {
        play[0].pos.x -= 1, play[0].pos.y += 1;
        return true;
    }
    if (keys[5] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x + 1][(int)play[0].pos.y + 1], &play[0]))) {
        play[0].pos.x += 1, play[0].pos.y += 1;
        return true;
    }
    if (keys[6] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x - 1][(int)play[0].pos.y - 1], &play[0]))) {
        play[0].pos.x -= 1, play[0].pos.y -= 1;
        return true;
    }
    if (keys[7] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x + 1][(int)play[0].pos.y - 1], &play[0]))) {
        play[0].pos.x += 1, play[0].pos.y -= 1;
        return true;
    }
    return false;
}

static void move_players(char **first_floor, char **second_floor,
    entity_t play[], int keys[])
{
    char **map = NULL;

    if (play[0].floor == 0)
        map = first_floor;
    else
        map = second_floor;
    if (move_players_split(map, play, keys))
        return;
    if (keys[0] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x][(int)play[0].pos.y + 1], &play[0])))
        play[0].pos.y += 1;
    if (keys[1] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x][(int)play[0].pos.y - 1], &play[0])))
        play[0].pos.y -= 1;
    if (keys[2] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x - 1][(int)play[0].pos.y], &play[0])))
        play[0].pos.x -= 1;
    if (keys[3] == 1 && !(is_obstacle
        (map[(int)play[0].pos.x + 1][(int)play[0].pos.y], &play[0])))
        play[0].pos.x += 1;
}

bool game_loop(
    char **first_floor, char **second_floor, entity_t play[], int keys[])
{
    move_players(first_floor, second_floor, play, keys);
    if (check_death(first_floor, second_floor, &play[0]))
        return true;
    return false;
}
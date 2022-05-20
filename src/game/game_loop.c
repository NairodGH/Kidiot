/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "kidiot.h"

static bool check_death(char **first_floor, char **second_floor, entity_t player)
{
    if (player.floor == 0) {
        if (first_floor[(int)player.pos.x][(int)player.pos.y] == '#' ||
            first_floor[(int)player.pos.x][(int)player.pos.y] == 'O' ||
            first_floor[(int)player.pos.x][(int)player.pos.y]  == 'F')
            return true;
    }
    if (player.floor == 1) {
        if (second_floor[(int)player.pos.x][(int)player.pos.y] == '#' ||
            second_floor[(int)player.pos.x][(int)player.pos.y] == 'O' ||
            second_floor[(int)player.pos.x][(int)player.pos.y]  == 'F')
            return true;
    }
    return false;
}

static bool is_obstacle(char obs)
{
    if (obs == 'F' || obs == '#' || obs == 'O')
        return true;
    return false;
}

static bool move_players_split(char **map, entity_t players[], int keys[])
{
    if (keys[4] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x + 1][(int)players[0].pos.y - 1]))) {
        players[0].pos.x += 1, players[0].pos.y -= 1;
        return true;
    }
    if (keys[5] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x + 1][(int)players[0].pos.y + 1]))) {
        players[0].pos.x += 1, players[0].pos.y += 1;
        return true;
    }
    if (keys[6] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x - 1][(int)players[0].pos.y - 1]))) {
        players[0].pos.x -= 1, players[0].pos.y -= 1;
        return true;
    }
    if (keys[7] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x - 1][(int)players[0].pos.y + 1]))) {
        players[0].pos.x -= 1, players[0].pos.y += 1;
        return true;
    }
    return false;
}

static void move_players(char **first_floor, char **second_floor,
    entity_t players[], int keys[])
{
    char **map = NULL;

    if (players[0].floor == 0)
        map = first_floor;
    else
        map = second_floor;
    if (move_players_split(map, players, keys))
        return;
    if (keys[0] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x + 1][(int)players[0].pos.y])))
        players[0].pos.x += 1;
    if (keys[1] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x - 1][(int)players[0].pos.y])))
        players[0].pos.x -= 1;
    if (keys[2] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x][(int)players[0].pos.y - 1])))
        players[0].pos.y -= 1;
    if (keys[3] == 1 && !(is_obstacle
        (map[(int)players[0].pos.x][(int)players[0].pos.y + 1])))
        players[0].pos.y += 1;
}

bool game_loop(
    char **first_floor, char **second_floor, entity_t players[], int keys[])
{
    move_players(first_floor, second_floor, players, keys);
    if (check_death(first_floor, second_floor, players[0]))
        return true;
    return false;
}
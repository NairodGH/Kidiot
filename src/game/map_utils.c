/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "include.h"

size_t count_new_line(char *str)
{
    size_t i = 0;
    size_t ret = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            ret++;
        i++;
    }
    return ret;
}

size_t count_string_len(char *str)
{
    size_t i = 0;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    return i;
}

char **get_map(char *str)
{
    size_t new_line = count_new_line(str);
    char **map = malloc(sizeof(char *) * (new_line + 1));
    size_t x = 0;
    size_t y = 0;

    if (!map) {
        fprintf(stderr, "\033[1;31m[ERROR]\033[0m can't malloc\n");
        return NULL;
    }
    for (size_t i = 0; x != new_line; x++) {
        map[x] = malloc(sizeof(char) * (count_string_len(str + i) + 1));
        for (y = 0; str[i] != '\n'; y++) {
            map[x][y] = str[i];
            i++;
        }
        i++;
        map[x][y] = '\0';
    }
    map[x] = NULL;
    return map;
}
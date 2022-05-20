/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "kidiot.h"

static char *open_file(int fd, struct stat *stats, char *path)
{
    char *buffer = NULL;

    if (fd == -1) {
        fprintf(stderr, "\033[1;31m[ERROR]\033[0m can't open file\n");
        return NULL;
    }
    if (stat(path, stats) != 0) {
        fprintf(stderr, "\033[1;31m[ERROR]\033[0m can't stat file\n");
        close(fd);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (stats->st_size + 1));
    if (!buffer) {
        fprintf(stderr, "\033[1;31m[ERROR]\033[0m can't malloc\n");
        close(fd);
        return NULL;
    }
    return buffer;
}

char **read_map(char *path)
{
    int fd = open(path, O_RDWR);
    struct stat stats;
    int ret = 0;
    char *buffer = open_file(fd, &stats, path);
    char **map = NULL;

    if (!buffer)
        return NULL;
    ret = read(fd, buffer, stats.st_size);
    if (ret == -1) {
        fprintf(stderr, "\033[1;31m[ERROR]\033[0m can't read file\n");
        free(buffer);
        return NULL;
    }
    buffer[ret] = '\0';
    close (fd);
    map = get_map(buffer);
    free(buffer);
    return (map);
}

entity_t *init_entity()
{
    entity_t *entity = malloc(sizeof(entity_t) * 2);
    inv_t inv = {false, false, false};

    if (!entity)
        return NULL;
    entity[0].pos.x = 3;
    entity[0].pos.y = 3;
    entity[1].pos.x = 7;
    entity[1].pos.y = 7;
    entity[0].floor = 0;
    entity[1].floor = 1;
    entity[0].inv = inv;
    entity[1].inv = inv;
    return entity;
}

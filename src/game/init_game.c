/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "include.h"

static char *open_file(int fd, struct stat *stats, char *path)
{
    char *buffer = NULL;

    if (fd == -1) {
        fprintf(stderr, "%s[ERROR]%s Couldn't open the file\n", R, W);
        return NULL;
    }
    if (stat(path, stats) != 0) {
        fprintf(stderr, "%s[ERROR]%s Couldn't stat file\n", R, W);
        close(fd);
        return NULL;
    }
    buffer = calloc(stats->st_size + 1, sizeof(char));
    if (!buffer) {
        fprintf(stderr, "%s[ERROR]%s Couldn't malloc\n", R, W);
        close(fd);
        return NULL;
    }
    return buffer;
}

char **read_map(char *path)
{
    int fd = open(path, O_RDWR);
    struct stat stats;
    char *buffer = open_file(fd, &stats, path);
    char **map = NULL;

    if ((read(fd, buffer, stats.st_size)) == -1) {
        fprintf(stderr, "%s[ERROR]%s Couldn't read file\n", R, W);
        free(buffer);
        return NULL;
    }
    close (fd);
    map = get_map(buffer);
    free(buffer);
    return (map);
}

entity_t *init_entity(char **first_floor, char **second_floor)
{
    entity_t *entity = malloc(sizeof(entity_t) * 1);
    baby_t *baby = malloc(sizeof(baby_t) * 1);
    mom_t *mom = malloc(sizeof(mom_t) * 1);

    if (!entity || !baby || !mom)
        return NULL;
    baby->floor = 0;
    baby->hp = 100;
    mom->floor = 0;
    entity->first_floor = first_floor;
    entity->second_floor = second_floor;
    baby->pos = find_spawn_pos('b', entity->first_floor);
    mom->pos = find_spawn_pos('m', entity->first_floor);
    entity->baby = baby;
    entity->mom = mom;
    return entity;
}

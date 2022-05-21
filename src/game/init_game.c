/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

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

tp_t *init_tp(char **first_floor, char **second_floor)
{
    tp_t *tp = malloc(sizeof(tp_t) * 1);

    if (!tp)
        return NULL;
    tp->pos_stairs[0] = find_spawn_pos('S', first_floor);
    tp->pos_stairs[1] = find_spawn_pos('S', second_floor);
    tp->pos_toilet[0] = find_spawn_pos('W', first_floor);
    tp->pos_toilet[1] = find_spawn_pos('W', second_floor);
    return tp;
}

void init_obs(baby_t *baby)
{
    frigde_t *frigde = malloc(sizeof(frigde_t) * 1);
    cactus_t *cactus = malloc(sizeof(cactus_t) * 1);
    bathtub_t *bathtub = malloc(sizeof(bathtub_t) * 1);
    electric_t *electric = malloc(sizeof(electric_t) * 1);
    oven_t *oven = malloc(sizeof(oven_t) * 1);

    cactus->is_cut = false;
    cactus->time = 0;
    frigde->is_open = false;
    frigde->time = 0;
    bathtub->is_open = false;
    bathtub->time = 4;
    electric->is_fixed = false;
    electric->time = 5;
    oven->is_open = false;
    oven->is_burning = false;
    oven->time = 3;
    oven->time_burn = 1;
    baby->floor = 0;
    baby->hp = 100;
    baby->cactus = cactus;
    baby->fridge = frigde;
    baby->bathtub = bathtub;
    baby->electric = electric;
    baby->oven = oven;
    baby->speed = 0.1;
}

kidiot_t *init_kidiot(char **first_floor, char **second_floor)
{
    kidiot_t *kidiot = malloc(sizeof(kidiot_t) * 1);
    baby_t *baby = malloc(sizeof(baby_t) * 1);
    mom_t *mom = malloc(sizeof(mom_t) * 1);

    if (!kidiot || !baby || !mom)
        return NULL;
    init_obs(baby);
    mom->floor = 0;
    mom->speed = 0.1;
    kidiot->first_floor = first_floor;
    kidiot->second_floor = second_floor;
    baby->pos = find_spawn_pos('b', kidiot->first_floor);
    mom->pos = find_spawn_pos('m', kidiot->first_floor);
    baby->temp_pos = baby->pos;
    mom->temp_pos = mom->pos;
    kidiot->tp = init_tp(kidiot->first_floor, kidiot->second_floor);
    if (!kidiot->tp)
        return NULL;
    kidiot->baby = baby;
    kidiot->mom = mom;
    kidiot->textures[0] = LoadTexture("ressources/maggie.png");
    kidiot->textures[1] = LoadTexture("ressources/marge.png");
    kidiot->textures[2] = LoadTexture("ressources/misc.png");
    kidiot->textures[3] = LoadTexture("ressources/electricity.png");
    return kidiot;
}

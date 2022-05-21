/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#pragma once

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include "raylib.h"

typedef struct {
    bool is_cut;
    float time;
} cactus_t;

typedef struct {
    bool is_open;
    bool is_burning;
    float time;
    float time_burn;
} oven_t;

typedef struct {
    bool is_open;
    float time;
} bathtub_t;

typedef struct {
    bool is_fixed;
    float time;
} electric_t;

typedef struct {
    bool is_open;
    float time;
} frigde_t;

typedef struct baby_s {
    Vector2 pos;
    int floor;
    int hp;
    cactus_t *cactus;
    frigde_t *fridge;
    bathtub_t *bathtub;
    electric_t *electric;
    oven_t *oven;
} baby_t;

typedef struct {
    Vector2 pos;
    int floor;
} mom_t;

typedef struct {
    Vector2 pos_toilet[2];
    float time;
    Vector2 pos_stairs[2];
} tp_t;

typedef struct {
    baby_t *baby;
    mom_t *mom;
    tp_t *tp;
    char **first_floor;
    char **second_floor;
    Texture2D textures[4];
    int *keys;
} kidiot_t;

#define R "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define B "\033[1;34m"
#define M "\033[1;35m"
#define C "\033[1;36m"
#define W "\033[1;0m"

char **read_map(char *path);
bool game_loop(kidiot_t *play, int keys[]);
char **get_map(char *str);
int get_map_size(char **map);

void print_double_tab(char **map);
void free_double_tab(char **map);

kidiot_t *init_kidiot(char **first_floor, char **second_floor);
Vector2 find_spawn_pos(char cell, char **map);
void print_keys(int keys[]);

bool is_obstacle(char obs, kidiot_t *play, bool baby);
void move_players_mom(kidiot_t *play, int keys[]);
void move_players_baby(kidiot_t *play, int keys[]);

void draw_map(kidiot_t *play);

void gest_clock(kidiot_t *players);

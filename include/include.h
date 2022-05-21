/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include "raylib.h"

typedef struct baby_s {
    Vector2 pos;
    int floor;
    int hp;
} baby_t;

typedef struct mom_s {
    Vector2 pos;
    int floor;
} mom_t;

typedef struct entity_s {
    baby_t *baby;
    mom_t *mom;
} entity_t;

typedef struct {
    Texture2D texture;
    Vector2 frameSize;
    int maxFrame;
    int framesWide;
    Vector2 origin;
    int frame;
} sprite_t;

#define R "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define B "\033[1;34m"
#define M "\033[1;35m"
#define C "\033[1;36m"
#define W "\033[1;0m"

char **read_map(char *path);
bool game_loop(char **floor_1, char **floor_2, entity_t players[], int keys[]);
char **get_map(char *str);
int get_map_size(char **map);

void print_double_tab(char **map);
void free_double_tab(char **map);

entity_t *init_entity(char **map);
Vector2 find_spawn_pos(char cell, char **map);

bool is_obstacle(char obs, entity_t *play);
void move_players_mom(char **floor_1, char **floor_2,
    entity_t *play, int keys[]);
void move_players_baby(char **floor_1, char **floor_2,
    entity_t *play, int keys[]);

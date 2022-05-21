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
#include "raylib.h"

typedef struct {
    Vector2 pos;
    int floor;
    int hp;
} entity_t;

char **read_map(char *path);
bool game_loop(char **floor_1, char **floor_2, entity_t players[], int keys[]);
char **get_map(char *str);
int get_map_size(char **map);

void print_double_tab(char **map);
void free_double_tab(char **map);

entity_t *init_entity();
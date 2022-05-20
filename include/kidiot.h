/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#pragma once

#include "include.h"
#include "entity.h"

// Function :
char **read_map(char *path);
bool game_loop(
    char **first_floor, char **second_floor, entity_t players[], int keys[]);
char **get_map(char *str);

void print_double_tab(char **map);
void free_double_tab(char **map);

entity_t *init_entity();

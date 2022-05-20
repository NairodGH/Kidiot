/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#pragma once

#include "include.h"

typedef struct inv_s {
    bool knife;
    bool poison;
    bool fork;
} inv_t;

typedef struct entity_s {
    Vector2 pos;
    int floor;
    inv_t inv;
    int hp;
} entity_t;
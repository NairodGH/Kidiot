/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

electric_t *init_elec(kidiot_t *kidiot)
{
    size_t i = 0;
    int floor = 0;
    Vector2 *nb_cac = find_all_cell(kidiot->first_floor, 'E');
    Vector2 *nb_cac_s = find_all_cell(kidiot->second_floor, 'E');
    electric_t *elec = malloc(sizeof(electric_t) *
        (get_len_vect(nb_cac) + get_len_vect(nb_cac_s) + 1));

    for (size_t v = 0; i != get_len_vect(nb_cac); i++, v++) {
        elec[i].pos = nb_cac[v];
        elec[i].time = 5;
        elec[i].is_fixed = false;
        elec[i].floor = 0;
    }
    for (size_t v = 0, nb = 0; nb != get_len_vect(nb_cac_s); i++, v++, nb++) {
        elec[i].pos = nb_cac_s[v];
        elec[i].time = 5;
        elec[i].is_fixed = false;
        elec[i].floor = 1;
    }
    elec[i].floor = -1;
    return elec;
}


cactus_t *init_cactus(kidiot_t *kidiot)
{
    size_t i = 0;
    int floor = 0;
    Vector2 *nb_cac = find_all_cell(kidiot->first_floor, 'C');
    Vector2 *nb_cac_s = find_all_cell(kidiot->second_floor, 'C');
    cactus_t *cactus = malloc(sizeof(cactus_t) *
        (get_len_vect(nb_cac) + get_len_vect(nb_cac_s) + 1));

    for (size_t v = 0; i != get_len_vect(nb_cac); i++, v++) {
        cactus[i].pos = nb_cac[v];
        cactus[i].time = 2;
        cactus[i].is_cut = false;
        cactus[i].floor = 0;
    }
    for (size_t v = 0, nb = 0; nb != get_len_vect(nb_cac_s); i++, v++, nb++) {
        cactus[i].pos = nb_cac_s[v];
        cactus[i].time = 2;
        cactus[i].is_cut = false;
        cactus[i].floor = 1;
    }
    cactus[i].floor = -1;
    return cactus;
}
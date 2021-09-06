/*
** EPITECH PROJECT, 2021
** put_back_loc.c
** File description:
** put_back_loc function
*/

#include "struct.h"

void put_back_loc(map_i_t *map_i)
{
    int nb_loc_remaining = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; i < map_i->nb_loc_cpy; ++i) {
        row = map_i->loc_coord[i].row;
        col = map_i->loc_coord[i].col;
        if (map_i->map[row][col] == ' ') {
            map_i->map[row][col] = 'O';
            ++nb_loc_remaining;
        }
        nb_loc_remaining += (map_i->map[row][col] == 'O');
        nb_loc_remaining += (map_i->map[row][col] == 'P');
    }
    if (nb_loc_remaining != 0)
        map_i->nb_loc = nb_loc_remaining;
}
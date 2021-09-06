/*
** EPITECH PROJECT, 2021
** blocked.c
** File description:
** blocked related function
*/

#include "struct.h"

int verif_blocked(map_i_t *map_i, int i, int j)
{
    if ((map_i->map[i - 1][j] == '#' || map_i->map[i - 1][j] == 'X') &&
        (map_i->map[i][j - 1] == '#' || map_i->map[i][j + 1] == '#' ||
        map_i->map[i][j - 1] == 'X' || map_i->map[i][j + 1] == 'X'))
        return 1;
    if ((map_i->map[i + 1][j] == '#' || map_i->map[i + 1][j] == 'X') &&
        (map_i->map[i][j - 1] == '#' || map_i->map[i][j + 1] == '#' ||
        map_i->map[i][j - 1] == 'X' || map_i->map[i][j + 1] == 'X'))
        return 1;
    return 0;
}

int is_blocked(map_i_t *map_i)
{
    int nb_blocked_boxes = 0;

    for (int i = 0; map_i->map[i]; ++i)
        for (int j = 0; map_i->map[i][j]; ++j) {
            if (map_i->map[i][j] == 'X' && verif_blocked(map_i, i, j) == 1)
                ++nb_blocked_boxes;
        }
    return (nb_blocked_boxes == map_i->nb_boxes);
}
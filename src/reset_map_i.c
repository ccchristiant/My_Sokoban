/*
** EPITECH PROJECT, 2021
** reset_map_i.c
** File description:
** reset_map_i function
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void reset_map_i(map_i_t *map_i)
{
    free_double_tab(map_i->map);
    map_i->map = copy_tab(map_i->map_cpy);
    map_i->p_coord = map_i->p_coord_cpy;
    map_i->nb_loc = map_i->nb_loc_cpy;
}
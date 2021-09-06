/*
** EPITECH PROJECT, 2021
** reset_map_i.c
** File description:
** reset_map_i function
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>
#include <fmod/fmod.h>

void reset_map_i(map_i_t *map_i)
{
    FMOD_System_PlaySound(map_i->system, map_i->reset, 0, 0, &map_i->chan_4);
    FMOD_Channel_SetVolume(map_i->chan_4, (map_i->v_sounds == 1) ? 0.2 : 0);
    free_double_tab(map_i->map);
    map_i->map = copy_tab(map_i->map_cpy);
    map_i->p_coord = map_i->p_coord_cpy;
    map_i->nb_loc = map_i->nb_loc_cpy;
    map_i->diff = clock();
    map_i->nb_moves = 0;
    map_i->blocked = 0;
}
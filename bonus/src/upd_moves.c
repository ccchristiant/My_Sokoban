/*
** EPITECH PROJECT, 2021
** upd_moves.c
** File description:
** upd_moves function
*/

#include "struct.h"
#include <stdlib.h>

void upd_move(map_i_t *map_i, row_col coord)
{
    map_i->map[coord.row][coord.col] = 'P';
    map_i->map[map_i->p_coord.row][map_i->p_coord.col] = ' ';
    map_i->p_coord.row = coord.row;
    map_i->p_coord.col = coord.col;
    ++map_i->nb_moves;
}

void upd_push(map_i_t *map_i, row_col coord, row_col coord_2)
{
    if (map_i->map[coord_2.row][coord_2.col] == 'O') {
        --map_i->nb_loc;
        if (map_i->nb_loc != 0) {
            FMOD_System_PlaySound(map_i->system, map_i->box_placed, 0, 0, &map_i->chan_3);
            FMOD_Channel_SetVolume(map_i->chan_3, (map_i->v_sounds == 1) ? 1 : 0);
        }
        else {
            FMOD_System_PlaySound(map_i->system, map_i->pause_end, 0, 0, &map_i->chan_3);
            FMOD_Channel_SetVolume(map_i->chan_3, (map_i->v_sounds == 1) ? 0.7 : 0);
        }
    }
    map_i->map[coord.row][coord.col] = 'P';
    map_i->map[coord_2.row][coord_2.col] = 'X';
    map_i->map[map_i->p_coord.row][map_i->p_coord.col] = ' ';
    map_i->p_coord.row = coord.row;
    map_i->p_coord.col = coord.col;
    ++map_i->nb_moves;
}
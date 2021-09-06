/*
** EPITECH PROJECT, 2021
** moves.c
** File description:
** moves function
*/

#include "sokoban.h"

void move_push(map_i_t *map_i, row_col index)
{
    row_col coord;
    row_col coord_2;
    coord.row = map_i->p_coord.row + index.row;
    coord.col = map_i->p_coord.col + index.col;
    coord_2.row = coord.row + index.row;
    coord_2.col = coord.col + index.col;

    if (map_i->map[coord.row][coord.col] == ' ' ||
        map_i->map[coord.row][coord.col] == 'O') {
        upd_move(map_i, coord);
        return;
    }
    if (map_i->map[coord.row][coord.col] == 'X' &&
        (map_i->map[coord.row + index.row][coord.col + index.col] == ' ' ||
         map_i->map[coord.row + index.row][coord.col + index.col] == 'O'))
        upd_push(map_i, coord, coord_2);
}
/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban header
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "struct.h"

int manual(int ac, char **av);
int error(int ac, char **av, map_i_t *map_i);
int sokoban(map_i_t *map_i);
void init_term(void);
void end_term(map_i_t *map_i);
int game_loop(map_i_t *map_i);
void display(map_i_t *map_i);
void reset_map_i(map_i_t *map_i);
void move_push(map_i_t *map_i, row_col index);
void upd_move(map_i_t *map_i, row_col coord);
void upd_push(map_i_t *map_i, row_col coord, row_col coord_2);
int is_blocked(map_i_t *map_i);
void put_back_loc(map_i_t *map_i);

#endif
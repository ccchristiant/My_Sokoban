/*
** EPITECH PROJECT, 2021
** sokoban.c
** File description:
** sokoban function
*/

#include "sokoban.h"

int sokoban(map_i_t *map_i)
{
    int ret_val;

    init_term(map_i);
    ret_val = game_loop(map_i);
    end_term(map_i);
    return ret_val;
}
/*
** EPITECH PROJECT, 2021
** init_end_term.c
** File description:
** init_end_term function
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <ncurses.h>

void init_term(void)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
}

void end_term(map_i_t *map_i)
{
    endwin();
    free_double_tab(map_i->map);
    free_double_tab(map_i->map_cpy);
    free(map_i->loc_coord);
}
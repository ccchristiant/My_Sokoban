/*
** EPITECH PROJECT, 2021
** display.c
** File description:
** display function
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <ncurses.h>

void display(map_i_t *map_i)
{
    row_col scr_dim;
    int row;
    int col;
    char *str = "Please enlarge the terminal";

    getmaxyx(stdscr, scr_dim.row, scr_dim.col);
    row = (scr_dim.row - map_i->nb_row) / 2;
    col = (scr_dim.col - map_i->nb_col) / 2;
    if (map_i->nb_col <= scr_dim.col && map_i->nb_row < scr_dim.row)
        for (int i = 0; map_i->map[i]; ++i)
            mvprintw(row + i, col, map_i->map[i]);
    else
        mvprintw(scr_dim.row / 2, (scr_dim.col - my_strlen(str)) / 2, str);
}
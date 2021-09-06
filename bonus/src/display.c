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
#include <time.h>
#include "enum.h"
#include <fmod/fmod.h>

void display_with_color(int row, int col, char c)
{
    switch (c)
    {
        case ' ':
            attron(COLOR_PAIR(EMPTY));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(EMPTY));
            break;
        case '#':
            attron(COLOR_PAIR(WALL));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(WALL));
            break;
        case 'X':
            attron(COLOR_PAIR(BOX));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(BOX));
            break;
        case 'O':
            attron(COLOR_PAIR(STORAGE));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(STORAGE));
            break;
        case 'P':
            attron(COLOR_PAIR(PLAYER));
            mvaddch(row, col, c);
            attroff(COLOR_PAIR(PLAYER));
            break;
    }
}

void display(map_i_t *map_i)
{
    row_col scr_dim;
    int row;
    int col;
    char *str = "Please enlarge the terminal";

    getmaxyx(stdscr, scr_dim.row, scr_dim.col);
    row = (scr_dim.row - map_i->nb_row) / 2;
    col = (scr_dim.col - map_i->nb_col) / 2;
    if (map_i->nb_col <= scr_dim.col && map_i->nb_row < scr_dim.row) {
        mvprintw(row - 4, scr_dim.col / 2 - 8, "Timer : %f", map_i->time / CLOCKS_PER_SEC);
        mvprintw(row - 2, scr_dim.col / 2 - 9, "Number of moves : %d", map_i->nb_moves);
        attron(A_BLINK);
        mvprintw(row + map_i->nb_row + 1, scr_dim.col / 2 - 10, "Press SPACE to restart");
        attroff(A_BLINK);
        for (int x = 0; map_i->map[x]; ++x)
            for (int y = 0; map_i->map[x][y] != '\0'; ++y)
                display_with_color(row + x, col + y, map_i->map[x][y]);
        if (map_i->nb_loc == 0)
            mvprintw(row - 6, scr_dim.col / 2 - 5, "Victory !");
        if (map_i->blocked == 1)
            mvprintw(row - 6, scr_dim.col / 2 - 4, "Defeat !");
    }
    else
        mvprintw(scr_dim.row / 2, (scr_dim.col - my_strlen(str)) / 2, str);
}
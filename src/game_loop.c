/*
** EPITECH PROJECT, 2021
** game_loop.c
** File description:
** game_loop function
*/

#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>

static const sokoban_matcher tab[4] = {
    {KEY_UP, (row_col){-1, 0}, &move_push},
    {KEY_LEFT, (row_col){0, -1}, &move_push},
    {KEY_DOWN, (row_col){1, 0}, &move_push},
    {KEY_RIGHT, (row_col){0, 1}, &move_push},
};

int game_loop(map_i_t *map_i)
{
    int move = 0;
    int blocked = 0;
    while (map_i->nb_loc != 0 && move != 27 && blocked != 1) {
        display(map_i);
        move = getch();
        if (move == ' ')
            reset_map_i(map_i);
        for (int idx = 0; idx < 4; ++idx)
            if (move == tab[idx].move)
                tab[idx].function(map_i, tab[idx].index);
        put_back_loc(map_i);
        if (map_i->nb_loc != 0)
            blocked = is_blocked(map_i);
        refresh();
        erase();
    }
    display(map_i);
    refresh();
    usleep(200000);
    return blocked;
}
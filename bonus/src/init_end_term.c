/*
** EPITECH PROJECT, 2021
** init_end_term.c
** File description:
** init_end_term function
*/

#include "my.h"
#include "enum.h"
#include "macros.h"
#include "sokoban.h"
#include <stdlib.h>
#include <stdio.h>

void init_term(map_i_t *map_i)
{
    initscr();
    cbreak();
    noecho();
    clear();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    init_colors();
    init_sound(map_i);
    map_i->diff = map_i->nb_moves = map_i->pause = map_i->exit = 0;
    map_i->startx = (COLS - WIDTH) / 2;
    map_i->starty = (LINES - HEIGHT) / 2;
    map_i->menu_win = newwin(HEIGHT, WIDTH, map_i->starty, map_i->startx);
    map_i->menu = map_i->v_sounds = 1;
    keypad(map_i->menu_win, TRUE);
    nodelay(map_i->menu_win, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
}

void end_term(map_i_t *map_i)
{
    delwin(map_i->menu_win);
    endwin();
    free_double_tab(map_i->map);
    free_double_tab(map_i->map_cpy);
    free(map_i->loc_coord);
    FMOD_Sound_Release(map_i->box_placed);
    FMOD_Sound_Release(map_i->music);
    FMOD_Sound_Release(map_i->pause_end);
    FMOD_Sound_Release(map_i->reset);
    FMOD_Sound_Release(map_i->click);
    FMOD_System_Close(map_i->system);
    FMOD_System_Release(map_i->system);
}
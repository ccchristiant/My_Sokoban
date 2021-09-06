/*
** EPITECH PROJECT, 2021
** game_loop.move
** File description:
** game_loop function
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "macros.h"
#include "enum.h"
#include <fmod/fmod.h>

char *choices[] = {"Start", "Music", "Sound", "Exit", "Resume"};

static const sokoban_matcher tab[4] = {
    {KEY_UP, (row_col){-1, 0}, &move_push},
    {KEY_LEFT, (row_col){0, -1}, &move_push},
    {KEY_DOWN, (row_col){1, 0}, &move_push},
    {KEY_RIGHT, (row_col){0, 1}, &move_push},
};

void print_menu(WINDOW *menu_win, int highlight)
{
    wattron(menu_win, COLOR_PAIR(MENU_BORDER));
    box(menu_win, 0, 0);
    wattroff(menu_win, COLOR_PAIR(MENU_BORDER));
    wattron(menu_win, A_BOLD);
    mvwprintw(menu_win, 3, WIDTH / 2 - 4, "MySokoban");
    mvwprintw(menu_win, 4, WIDTH / 2 - 5, "Tran Studios");
    wattroff(menu_win, A_BOLD);
    for (int i = 0, x = 7, y = 9; i < 4; ++i, y += 2) {
        wattron(menu_win, A_ITALIC);
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE | COLOR_PAIR(HIGHLIGHT));
            mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE | COLOR_PAIR(HIGHLIGHT));
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        wattroff(menu_win, A_ITALIC);
        if (my_strcmp(choices[i], "Music") == 0 || my_strcmp(choices[i], "Sound") == 0)
            mvwprintw(menu_win, y, x + my_strlen(choices[i]) + 1, "ON / OFF");
    }
    wrefresh(menu_win);
}

void report_choice(int mouse_x, int mouse_y, int *p_choice, map_i_t *map_i)
{
    int i, j, choice;

    i = map_i->startx + 7;
    j = map_i->starty + 9;
    for (choice = 0; choice < 4; ++choice)
        if (mouse_y == j + 2 * choice && mouse_x >= i && mouse_x <= i + my_strlen(choices[choice]) - 1) {
            *p_choice = choice + 1;
            FMOD_System_PlaySound(map_i->system, map_i->click, 0, 0, &map_i->chan_2);
            FMOD_Channel_SetVolume(map_i->chan_2, (map_i->v_sounds == 1) ? 0.1 : 0);
            break;
        }
}

void exec_choice(int choice, map_i_t *map_i)
{
    switch (choice)
    {
        case 1:
            map_i->menu = 0;
            break;
        case 2:
            map_i->v_music = (map_i->v_music == 0) ? 0.1 : 0;
            FMOD_Channel_SetVolume(map_i->chan_1, map_i->v_music);
            break;
        case 3:
            map_i->v_sounds = (map_i->v_sounds == 0);
            break;
        case 4:
            map_i->exit = 1;
            break;
    }
}

int game_loop(map_i_t *map_i)
{
    int choice = 1;
    MEVENT event;
    int move = 1;
    int first_pause = 0;

    while (map_i->exit != 1) {
        if (map_i->menu == 1) {
            mvwin(map_i->menu_win, (LINES - HEIGHT) / 2, (COLS - WIDTH) / 2);
            attron(A_BLINK);
            mvprintw((LINES + HEIGHT) / 2 + 1, COLS / 2 - 17, "Press Enter to confirm your choice");
            attroff(A_BLINK);
            print_menu(map_i->menu_win, choice);
            move = wgetch(map_i->menu_win);
            if (move == KEY_MOUSE) {
                getmouse(&event);
                if (event.bstate & BUTTON1_CLICKED)
                    report_choice(event.x, event.y, &choice, map_i);
            }
            if ((move == KEY_UP && choice > 1) || (move == KEY_DOWN && choice < 4)) {
                choice -= (move == KEY_UP);
                choice += (move == KEY_DOWN);
                FMOD_System_PlaySound(map_i->system, map_i->click, 0, 0, &map_i->chan_2);
                FMOD_Channel_SetVolume(map_i->chan_2, (map_i->v_sounds == 1) ? 0.1 : 0);
            }
            if (move == 10)
                exec_choice(choice, map_i);
            refresh();
            if (move == KEY_RESIZE)
                erase();
            map_i->diff = (map_i->pause == 0) ? clock() : clock() - map_i->elapsed;
        }
        else {
            display(map_i);
            move = getch();
            if (move == ' ')
                reset_map_i(map_i);
            if (map_i->nb_loc != 0 && map_i->blocked != 1) {
                for (int idx = 0; idx < 4; ++idx)
                    if (move == tab[idx].move)
                        tab[idx].function(map_i, tab[idx].index);
                put_back_loc(map_i);
                if (map_i->nb_loc != 0)
                    map_i->blocked = is_blocked(map_i);
                map_i->time = clock() - map_i->diff;
            }
            refresh();
            erase();
            if (move == 'p') {
                map_i->menu = map_i->pause = 1;
                map_i->elapsed = map_i->time;
                if (first_pause == 0) {
                    str_swap(&choices[0], &choices[4]);
                    ++first_pause;
                }
            }
        }
    }
    if (map_i->menu == 0) {
        display(map_i);
        refresh();
        usleep(200000);
    }
    return map_i->blocked;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <fmod/fmod.h>

static const int WIDTH = 50;

static const int HEIGHT = 20;

char *choices[] = {"Start", "Music", "Sound", "Exit"};

void print_menu(WINDOW *menu_win, int highlight)
{
    int x, y, i;

    x = 7;
    y = 9;
    wattron(menu_win, COLOR_PAIR(1));
    box(menu_win, 0, 0);
    wattroff(menu_win, COLOR_PAIR(1));
    wattron(menu_win, A_BOLD);
    mvwprintw(menu_win, 4, WIDTH / 2 - 4, "MySokoban");
    wattroff(menu_win, A_BOLD);
    for (int i = 0; i < 4; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            wattron(menu_win, COLOR_PAIR(2));
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, COLOR_PAIR(2));
			wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        if (strcmp(choices[i], "Music") == 0 || strcmp(choices[i], "Sound") == 0)
            mvwprintw(menu_win, y, x + strlen(choices[i]) + 1, "ON / OFF");
        y += 2;
    }
    wrefresh(menu_win);
}

void report_choice(int mouse_x, int mouse_y, int *p_choice, FMOD_SOUND *click, FMOD_SYSTEM *system)
{
    int i, j, choice;
    FMOD_CHANNEL *chan;

    i = startx + 7;
    j = starty + 9;
    for (choice = 0; choice < 4; ++choice)
        if (mouse_y == j + 2 * choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice]) - 1) {
            *p_choice = choice + 1;
            FMOD_System_PlaySound(system, click, 0, 0, &chan);
            FMOD_Channel_SetVolume(chan, 0.2);
            break;
        }
}

void exec_choice(int choice, int *exit)
{
    switch (choice)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            *exit = 1;
            break;
    }
}

int main(void)
{
    FMOD_SYSTEM *system;
    FMOD_SOUND *click;
    FMOD_SOUND *music;
    FMOD_RESULT result;
    FMOD_CHANNEL *chan_1;
    FMOD_CHANNEL *chan_2;

    FMOD_System_Create(&system);
    FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);
    result = FMOD_System_CreateSound(system, "../sounds/coin.wav", FMOD_CREATESAMPLE, 0, &click);
    if (result != FMOD_OK) {
        fprintf(stderr, "Cannot read coin.wav\n");
        exit(84);
    }
    result = FMOD_System_CreateSound(system, "../sounds/jojo.mp3", FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &music);
    if (result != FMOD_OK) {
        fprintf(stderr, "Cannot read jojo.mp3\n");
        exit(84);
    }
    FMOD_Sound_SetLoopCount(music, -1);
    FMOD_System_PlaySound(system, music, 0, 0, &chan_2);
    FMOD_Channel_SetVolume(chan_2, 0.2);
    //Menu
    int c, choice = 1;
    int exit = 0;
    WINDOW *menu_win;
    MEVENT event;

    // Initialisation
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);

    startx = (COLS - WIDTH) / 2;
    starty = (LINES - HEIGHT) / 2;
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    nodelay(menu_win, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    while (c != 27 && exit != 1) {
        mvwin(menu_win, (LINES - HEIGHT) / 2, (COLS - WIDTH) / 2);
        attron(A_REVERSE);
        mvprintw((LINES - HEIGHT) / 2 - 2, COLS / 2 - 11, "Press Escape to quit");
        attroff(A_REVERSE);
        attron(A_BLINK);
        mvprintw((LINES + HEIGHT) / 2 + 1, COLS / 2 - 17, "Press Enter to confirm your choice");
        attroff(A_BLINK);
        print_menu(menu_win, choice);
        c = wgetch(menu_win);
        if (c == KEY_MOUSE) {
            getmouse(&event);
            if (event.bstate & BUTTON1_CLICKED)
                report_choice(event.x, event.y, &choice, click, system);
        }
        if ((c == KEY_UP && choice > 1) || (c == KEY_DOWN && choice < 4)) {
            choice -= (c == KEY_UP);
            choice += (c == KEY_DOWN);
            FMOD_System_PlaySound(system, click, 0, 0, &chan_1);
            FMOD_Channel_SetVolume(chan_1, 0.2);
        }
        if (c == 10)
            exec_choice(choice, &exit);
        refresh();
        if (c == KEY_RESIZE)
            erase();
    }
    // Ending
    delwin(menu_win);
    endwin();
    return 0;
}
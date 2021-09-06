/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "sokoban.h"
#include "my.h"
#include "struct.h"
#include <ncurses.h>

int main(int ac, char **av)
{
    map_i_t map_i;

    if (manual(ac, av) == 0)
        return 0;
    if (error(ac, av, &map_i) == 84)
        return 84;
    return sokoban(&map_i);
}
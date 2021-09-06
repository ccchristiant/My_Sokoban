/*
** EPITECH PROJECT, 2021
** manual.c
** File description:
** manual function
*/

#include "my.h"

int manual(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("USAGE\n");
        my_printf("\t./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tmap\tfile representing the warehouse map, containing ");
        my_printf("\'#\' for walls,\n\t\t\'P\' for player, \'X\' for boxes ");
        my_printf("and \'0\' for storage locations.\n");
        return 0;
    }
    return 84;
}
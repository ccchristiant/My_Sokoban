/*
** EPITECH PROJECT, 2021
** free_double_tab.c
** File description:
** free double tab function
*/

#include <stdlib.h>

void free_double_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
/*
** EPITECH PROJECT, 2021
** copy_tab.c
** File description:
** copy_tab function
*/

#include "../../include/my.h"
#include <stdlib.h>

char **copy_tab(char **tab)
{
    char **tab_cpy;
    int len = 0;

    for (; tab[len]; len++);
    tab_cpy = malloc(sizeof(char*) * (len + 1));
    for (int i = 0; i < len; i++)
        tab_cpy[i] = my_strdup(tab[i]);
    tab_cpy[len] = NULL;
    return (tab_cpy);
}
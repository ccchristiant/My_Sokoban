/*
** EPITECH PROJECT, 2021
** my_tab_length.c
** File description:
** tab length function
*/

int my_tab_length(char **tab)
{
    int len = 0;

    for (; tab[len]; len++);
    return len;
}
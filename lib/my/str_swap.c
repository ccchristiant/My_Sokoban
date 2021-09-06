/*
** EPITECH PROJECT, 2021
** str_swap.c
** File description:
** str swap
*/

void str_swap(char *str1[], char *str2[])
{
    char *t;

    t = *str1;
    *str1 = *str2;
    *str2 = t;
}

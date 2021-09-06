/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

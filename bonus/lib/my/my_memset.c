/*
** EPITECH PROJECT, 2021
** my_memset.c
** File description:
** memset function
*/

void *my_memset(void *s, int c, int n)
{
    unsigned char *ps = s;

    for (int i = 0; i < n; ++i)
        ps[i] = c;
    return s;
}
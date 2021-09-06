/*
** EPITECH PROJECT, 2021
** my_put_nbr_base.c
** File description:
** ctran
*/

#include "../../../include/my.h"

void my_put_nbr_base(char const *base, int nb)
{
    if (nb >= my_strlen(base))
        my_put_nbr_base(base, nb / my_strlen(base));
    my_putchar(base[nb % my_strlen(base)]);
}
/*
** EPITECH PROJECT, 2021
** after_backslash.c
** File description:
** ctran
*/

#include "../../../include/my.h"

void after_backslash(const char *format, int i)
{
    my_putchar('\\');
    switch (my_strlen(my_itoa(d_to_normal_base(format[i], 8)))) {
    case 1:
        my_putstr("00");
        break;
    case 2:
        my_putstr("0");
        break;
    }
    my_put_nbr(d_to_normal_base(format[i], 8));
}
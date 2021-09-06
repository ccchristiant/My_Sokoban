/*
** EPITECH PROJECT, 2021
** wrapper_1.c
** File description:
** ctran
*/

#include "../../../include/my.h"
#include <stdarg.h>

void wrapper_my_put_nbr(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void wrapper_my_putchar(va_list list)
{
    my_putchar((char)va_arg(list, int));
}

void wrapper_my_putstr(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void wrapper_my_put_bin(va_list list)
{
    my_put_nbr_base("01", va_arg(list, unsigned int));
}

void wrapper_my_put_oct(va_list list)
{
    my_put_nbr_base("01234567", va_arg(list, unsigned int));
}
/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my printf
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../include/my.h"
#include "../../../include/struct.h"

static const c_f array[10] = {
    {'i', &wrapper_my_put_nbr},
    {'d', &wrapper_my_put_nbr},
    {'c', &wrapper_my_putchar},
    {'s', &wrapper_my_putstr},
    {'b', &wrapper_my_put_bin},
    {'o', &wrapper_my_put_oct},
    {'C', &wrapper_my_putchar_oct},
    {'S', &wrapper_my_putstr_oct},
    {'x', &wrapper_my_put_hex},
    {'X', &wrapper_my_put_hex_maj},
};

void my_printf_child_loop(const char *format, va_list list, int *i)
{
    int j = 0;

    for (j = 0; j < 10; j++) {
        if (format[*i] == '%' && format[*i + 1] == array[j].c) {
            array[j].function(list);
            *i += 1;
            break;
        }
    }
    if (j == 10)
        my_putchar(format[*i]);
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++)
        my_printf_child_loop(format, list, &i);
    va_end(list);
    return (0);
}
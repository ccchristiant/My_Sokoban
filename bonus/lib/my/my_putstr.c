/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** put str
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, &str[0], my_strlen(str));
}

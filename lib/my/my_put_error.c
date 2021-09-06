/*
** EPITECH PROJECT, 2021
** my_put_error.c
** File description:
** ctran
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_put_error(char *str)
{
    write(2, &str[0], my_strlen(str));
}

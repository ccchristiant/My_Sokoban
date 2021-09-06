/*
** EPITECH PROJECT, 2021
** itoa.c
** File description:
** itoa
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_intlen(int nb)
{
    int div = 1;
    int count = 1;

    if (nb < 0)
        nb = nb * (-1);
    while (nb / div >= 1) {
        div = div * 10;
        count++;
    }
    return (count);
}

char *my_char_neg(int nb)
{
    int i = my_intlen(nb);
    char *str_min = malloc(sizeof(char) * i + 1);
    str_min[0] = '-';
    char *str = malloc(sizeof(char) * i);
    if (str == NULL)
        return (NULL);
    i--;
    str[i] = '\0';
    for (; i > 0; i--) {
        str[i - 1] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return (my_strcat(str_min, str));
}

char *my_itoa(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        return (my_char_neg(nb));
    }
    if (nb == 0)
        return ("0");
    int i = my_intlen(nb);
    char *str = malloc(sizeof(char) * i);
    if (str == NULL)
        return (NULL);
    i--;
    str[i] = '\0';
    for (; i > 0; i--) {
        str[i - 1] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return (str);
}
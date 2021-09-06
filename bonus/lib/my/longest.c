/*
** EPITECH PROJECT, 2021
** longest.c
** File description:
** longest
*/

#include <stddef.h>

int my_strlen(char const *str);

char *longest(char *nbr1, char *nbr2)
{
    if (my_strlen(nbr1) > my_strlen(nbr2))
        return (nbr1);
    if (my_strlen(nbr1) <= my_strlen(nbr2))
        return (nbr2);
}

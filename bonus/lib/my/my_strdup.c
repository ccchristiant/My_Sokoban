/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** str dup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 2));
    if (dest == NULL)
        return (NULL);
    return (my_strcpy(dest, src));
}

/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** str str
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j;

    while (str[i] != '\0') {
        j = 0;
        while (str[i + j] == to_find[j] && str[i + j]) {
            if (to_find[j + 1] == '\0')
                return (&str[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

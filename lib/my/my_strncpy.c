/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** str n cpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

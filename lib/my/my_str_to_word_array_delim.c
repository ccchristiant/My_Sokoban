/*
** EPITECH PROJECT, 2021
** my_str_to_word_array_delim.c
** File description:
** my str to world array delim
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int nb_sep2(char const *str, char const sep)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        if (str[i] == sep)
            nb += 1;
        i++;
    }
    return (nb);
}

char **my_str_to_word_array_delim(char const *str, char const sep)
{
    int j;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (nb_sep2(str, sep) + 2));

    for (int i = 0; i < my_strlen(str); i++) {
        for (j = 0; str[i + j] && str[i + j] != sep; j++);
        tab[k] = malloc(sizeof(char) * j + 1);
        my_strncpy(tab[k], &str[i], j);
        i += j;
        k++;
    }
    tab[nb_sep2(str, sep) + 1] = 0;
    return (tab);
}

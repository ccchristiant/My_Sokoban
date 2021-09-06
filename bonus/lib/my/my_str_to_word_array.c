/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my str to word array
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int nb_sep(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t')
            nb += 1;
        i++;
    }
    return (nb);
}

void child_loop(char **tab, char const *str, int *i, int *k)
{
    int j = 0;

    for (; str[*i + j] && (str[*i + j] != ' ' && str[*i + j] != '\t'); j++);
    if (j != 0) {
        tab[*k] = malloc(sizeof(char) * j + 1);
        my_strncpy(tab[*k], &str[*i], j);
        *i += j;
        *k += 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int k = 0;
    int nb_separators = nb_sep(str);
    char **tab = malloc(sizeof(char *) * (nb_separators + 2));

    for (int i = 0; i < my_strlen(str); i++)
        child_loop(tab, str, &i, &k);
    tab[nb_separators + 1] = NULL;
    return (tab);
}
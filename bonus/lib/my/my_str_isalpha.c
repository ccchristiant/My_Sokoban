/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** str is alpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}

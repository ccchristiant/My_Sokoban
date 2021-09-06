/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** str len
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
}

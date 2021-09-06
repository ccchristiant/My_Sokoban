/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** rev str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int i_inv;
    char tmp;

    while (str[i] != '\0')
        i++;
    i_inv = i - 1;
    i = 0;
    while (i < i_inv)
    {
        tmp = str[i];
        str[i] = str[i_inv];
        str[i_inv] = tmp;
        i += 1;
        i_inv -= 1;
    }
    return (str);
}

/*
** EPITECH PROJECT, 2021
** my_showstr.c
** File description:
** show str
*/

void my_putchar(char c);

int my_putstr(char *str);

char *my_revstr(char *str);

void *my_atoh(char c)
{
    char result = c;
    char str[3];
    int i = 0;

    while (result != 0) {
        str[i] = (result % 16);
        result = result / 16;
        i++;
    }
    str[i] = '\\';
    my_putstr(my_revstr(str));
}

int my_showstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 31)
            my_atoh(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}

/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my get nbr
*/

int my_getnbr(char const *str)
{
    int i;
    int sign;
    int nb;

    i = 0;
    sign = 1;
    nb = 0;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign *= -1;
        i += 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        if (nb < 0  && nb != -2147483648 || nb < 0 && sign != -1)
            return (0);
        i += 1;
    }
    return (sign * nb);
}

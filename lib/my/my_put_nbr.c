/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i;

    i = 0;
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            nb = nb + 1;
            i = 1;
        }
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr((nb % 10) + i);
    }
    else
        my_putchar(nb + '0');
    return (0);
}

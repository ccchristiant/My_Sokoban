/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** is prime
*/

int my_is_prime(int nb)
{
    int i;

    i = 2;
    if (nb < 2 || nb > 2147483647)
        return (0);
    while (i <= nb / 2)
    {
        if (nb % i == 0)
            return (0);
        i += 1;
    }
    return (1);
}

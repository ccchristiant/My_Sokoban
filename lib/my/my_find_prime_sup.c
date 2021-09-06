/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** find prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int j;

    j = 0;
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    while (my_is_prime(nb + j) == 0)
        j++;
    return (nb + j);
}

/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
    int square;
    int i;

    i = 1;
    if (nb > 2147483647)
        return (0);
    while (i <= nb)
    {
        square = i * i;
        if (square > nb)
            return (0);
        if (square == nb)
            return (i);
        i += 1;
    }
    return (0);
}

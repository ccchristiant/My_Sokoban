/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** is neg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
    {
        my_putchar('P');
    }
    else
    {
        my_putchar('N');
    }
    my_putchar('\n');
    return (0);
}

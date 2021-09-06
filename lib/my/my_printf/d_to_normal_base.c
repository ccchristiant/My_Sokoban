/*
** EPITECH PROJECT, 2021
** d_to_normal_base.c
** File description:
** ctran
*/

int d_to_normal_base(int dec, int len_base)
{
    int result = 0;
    int i = 1;

    while (dec != 0) {
        result += (dec % len_base) * i;
        dec /= len_base;
        i *= 10;
    }
    return (result);
}
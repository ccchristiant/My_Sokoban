/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** show word array
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;
    int length = 0;

    while (tab[length])
        length++;
    while (i < length) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}

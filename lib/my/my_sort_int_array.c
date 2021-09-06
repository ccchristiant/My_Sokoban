/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** sort int array
*/

void my_swap(int *a, int *b);

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;

    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (array[j] > array[j + 1])
                my_swap(&array[j], &array[j + 1]);
        }
    }
    return;
}

/*
** EPITECH PROJECT, 2021
** fs_open_file.c
** File description:
** ctran
*/

#include <fcntl.h>
#include "../../include/my.h"

int fs_open_file(char const *filepath)
{
    int file_descriptor = open(filepath, O_RDONLY);

    if (file_descriptor > 0)
        return (file_descriptor);
    else
        return (-1);
}
/*
** EPITECH PROJECT, 2021
** load_file_in_mem.c
** File description:
** load a map content in memory
*/

#include "../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    int fd = fs_open_file(filepath);
    struct stat info;
    char *buff = NULL;

    if (fd == -1 || stat(filepath, &info) == -1 || !S_ISREG(info.st_mode))
        return NULL;
    buff = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, buff, info.st_size) == 0)
        return NULL;
    buff[info.st_size] = '\0';
    close(fd);
    return buff;
}
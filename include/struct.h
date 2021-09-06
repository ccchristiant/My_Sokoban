/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdarg.h>

//NCURSES
typedef struct nb_rows_and_nb_columns
{
    int row;
    int col;
}row_col;

typedef struct map_and_info
{
    char **map;
    char **map_cpy;
    int nb_boxes;
    int nb_loc;
    int nb_loc_cpy;
    row_col p_coord;
    row_col p_coord_cpy;
    row_col *loc_coord;
    int nb_row;
    int nb_col;
}map_i_t;

//WRAPPER
struct match_printf {
    char c;
    void (*function)(va_list list);
};

typedef struct match_printf c_f;

struct match_minishell_1 {
    char *command;
    void (*function)(char **command_line, char ***env);
};

typedef struct match_minishell_1 command_matcher;

struct sokoban_arrows {
    int move;
    row_col index;
    void (*function)(map_i_t *map_i, row_col index);
};

typedef struct sokoban_arrows sokoban_matcher;

//LINKED LISTS
typedef struct linked_list_int
{
    int data;
    struct linked_list_int *next;
}linked_list_int_t;

typedef struct linked_list_str
{
    char *data;
    struct linked_list_str *next;
}linked_list_str_t;

#endif
/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error function
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>

void get_coords(map_i_t *map_i)
{
    int idx = 0;

    map_i->loc_coord = malloc(sizeof(row_col) * map_i->nb_loc);
    for (int i = 0; map_i->map[i]; ++i)
        for (int j = 0; map_i->map[i][j]; ++j) {
            if (map_i->map[i][j] == 'P') {
                map_i->p_coord.row = i;
                map_i->p_coord.col = j;
                map_i->p_coord_cpy = map_i->p_coord;
            }
            if (map_i->map[i][j] == 'O') {
                map_i->loc_coord[idx].row = i;
                map_i->loc_coord[idx].col = j;
                ++idx;
            }
        }
}

void upd_numbers(char c, int *nb_p, int *nb_boxes, int *nb_loc)
{
    *nb_p += (c == 'P');
    *nb_boxes += (c == 'X');
    *nb_loc += (c == 'O');
}

int matching_boxes_locations(map_i_t *map_i)
{
    int nb_p = 0;
    int nb_boxes = 0;
    int nb_loc = 0;

    for (int i = 0; map_i->map[i]; ++i)
        for (int j = 0; map_i->map[i][j] != '\0'; ++j) {
            if (map_i->map[i][j] != '#' && map_i->map[i][j] != 'P'
                && map_i->map[i][j] != 'X' && map_i->map[i][j] != 'O'
                && map_i->map[i][j] != ' ' && map_i->map[i][j] != '\n')
                return 84;
            upd_numbers(map_i->map[i][j], &nb_p, &nb_boxes, &nb_loc);
        }
    if (nb_p != 1 || (nb_boxes == 0 && nb_loc == 0) ||
        nb_boxes < nb_loc)
        return 84;
    map_i->nb_boxes = nb_boxes;
    map_i->nb_loc = nb_loc;
    map_i->nb_loc_cpy = nb_loc;
    get_coords(map_i);
    return 0;
}

int longest_line(char **tab)
{
    int len = 0;
    int max = 0;

    for (int i = 0; tab[i]; ++i) {
        len = my_strlen(tab[i]);
        max = (len > max) ? len : max;
    }
    return max;
}

int error(int ac, char **av, map_i_t *map_i)
{
    char *map;

    if (ac != 2)
        return 84;
    map = load_file_in_mem(av[1]);
    if (map == NULL)
        return 84;
    map_i->map = my_str_to_word_array_delim(map, '\n');
    map_i->map_cpy = copy_tab(map_i->map);
    free(map);
    if (matching_boxes_locations(map_i) == 84) {
        free(map_i->map);
        free(map_i->map_cpy);
        return 84;
    }
    map_i->nb_row = my_tab_length(map_i->map);
    map_i->nb_col = longest_line(map_i->map);
    return 0;
}
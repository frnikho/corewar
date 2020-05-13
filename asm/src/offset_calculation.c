/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** offset_calculation
*/

#include <my.h>
#include "corewar.h"
#include <stdlib.h>

void add_byte_core(corewar_t *corewar, int pre_nb, int *next_tab, int *values)
{
    for (int i = 0; i < pre_nb; i++) {
        next_tab[values[2]] = corewar->bytes_tab[i];
        values[2] ++;
        if (i == values[0]) {
            next_tab[values[2]] = values[1];
            values[2] ++;
            corewar->bytes_nb ++;
        }
    }
}

void push_request(corewar_t *corewar, int count_from, int index, char *name)
{
    shift_request_t **next_tab = NULL;
    shift_request_t *new = malloc(sizeof(shift_request_t));
    int i = 0;

    new->count_from = count_from;
    new->index = index;
    new->name = my_strdup(name);
    for (i = 0; corewar->shift_requests[i]; i++);
    next_tab = malloc(sizeof(shift_request_t*) * (i + 2));
    for (i = 0; corewar->shift_requests[i]; i++)
        next_tab[i] = corewar->shift_requests[i];
    next_tab[i] = new;
    next_tab[i+1] = NULL;
    free(corewar->shift_requests);
    corewar->shift_requests = next_tab;
}

void push_cursor(corewar_t *corewar, int position, char *name)
{
    cursor_shift_t **next_tab = NULL;
    cursor_shift_t *new = malloc(sizeof(shift_request_t));
    int i = 0;

    new->position = position;
    new->name = my_strdup(name);
    for (i = 0; corewar->cursor_shifts[i]; i++);
    next_tab = malloc(sizeof(cursor_shift_t*) * (i + 2));
    for (i = 0; corewar->cursor_shifts[i]; i++)
        next_tab[i] = corewar->cursor_shifts[i];
    next_tab[i] = new;
    next_tab[i+1] = NULL;
    free(corewar->cursor_shifts);
    corewar->cursor_shifts = next_tab;
}


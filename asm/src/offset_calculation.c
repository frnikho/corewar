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
/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** bytes_tab_tools
*/

#include <my.h>
#include "corewar.h"
#include <stdlib.h>

void push_byte(corewar_t *corewar, int byte)
{
    int *next_tab = malloc(sizeof(int) * (corewar->bytes_nb + 1));

    if (!corewar->bytes_tab)
        corewar->bytes_tab = malloc(sizeof(int) * corewar->bytes_nb);
    for (int i = 0; i < corewar->bytes_nb; i++)
        next_tab[i] = corewar->bytes_tab[i];
    next_tab[corewar->bytes_nb] = byte;
    corewar->bytes_nb++;
    if (corewar->bytes_tab)
        free(corewar->bytes_tab);
    corewar->bytes_tab = next_tab;
}

void pop_byte(corewar_t *corewar)
{
    int *next_tab = NULL;

    if (corewar->bytes_nb <= 0 || !corewar->bytes_tab)
        return;
    next_tab = malloc(sizeof(int) * (corewar->bytes_nb - 1));
    for (int i = 0; i < corewar->bytes_nb-1; i++)
        next_tab[i] = corewar->bytes_tab[i];
    corewar->bytes_nb--;
    if (corewar->bytes_tab)
        free(corewar->bytes_tab);
    corewar->bytes_tab = next_tab;
}

void del_byte(corewar_t *corewar, int index)
{
    int *next_tab = NULL;
    int new_i = 0;
    int pre_nb = corewar->bytes_nb;

    if (corewar->bytes_nb <= 0 || !corewar->bytes_tab)
        return;
    next_tab = malloc(sizeof(int) * (corewar->bytes_nb));
    for (int i = 0; i < pre_nb; i++) {
        if (i != index) {
            next_tab[new_i] = corewar->bytes_tab[i];
            new_i ++;
        } else
            corewar->bytes_nb --;
    }
    if (corewar->bytes_tab)
        free(corewar->bytes_tab);
    corewar->bytes_tab = next_tab;
}

void replace_byte(corewar_t *corewar, int index, int new_byte)
{
    if (corewar->bytes_nb <= 0 || !corewar->bytes_tab)
        return;
    if (index < corewar->bytes_nb && index >= 0)
        corewar->bytes_tab[index] = new_byte;
}

void add_byte(corewar_t *corewar, int index, int byte)
{
    int *next_tab = NULL;
    int new_i = 0;
    int pre_nb = corewar->bytes_nb;

    if (index < -1 || index >= corewar->bytes_nb)
        return;
    if (!corewar->bytes_tab)
        corewar->bytes_tab = malloc(sizeof(int) * corewar->bytes_nb);
    next_tab = malloc(sizeof(int) * (corewar->bytes_nb+1));
    if (-1 == index) {
        next_tab[new_i] = byte;
        new_i ++;
        corewar->bytes_nb ++;
    }
    add_byte_core(corewar, pre_nb, next_tab, (int []){index, byte, new_i});
    if (corewar->bytes_tab)
        free(corewar->bytes_tab);
    corewar->bytes_tab = next_tab;
}
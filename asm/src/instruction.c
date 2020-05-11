/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** instruction function
*/

#include "corewar.h"
op_t op_tab[] =
    {
        {"live", 1, {T_DIR}, 1, 10, live},
        {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 0},
        {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 0},
        {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 0},
        {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, and},
        {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 0},
        {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 0},
        {"zjmp", 1, {T_DIR}, 9, 20, zjmp},
        {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,0},
        {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,sti},
        {"fork", 1, {T_DIR}, 12, 800, 0},
        {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 0},
        {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,0},
        {"lfork", 1, {T_DIR}, 15, 1000, 0},
        {"aff", 1, {T_REG}, 16, 2, 0},
        {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 0},
        {0, 0, {0}, 0, 0, 0}
    };

op_t get_instruction(char *name)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (str_begin(name, op_tab[i].mnemonique))
            return op_tab[i];
    }
    return op_tab[16];
}
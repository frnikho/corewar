/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** instruction function
*/

#include <my.h>
#include "corewar.h"

op_t op_tab[] =
    {
        {"live", 1, {T_DIR}, 1, 10, live},
        {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, ld},
        {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, add},
        {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, sub},
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
        {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, st},
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

params get_params(char *params)
{
    int nbr = 0;

    for (int i = 0; params[i]; i++) {
        if (params[i] == ' ')
            continue;
        if (params[i] == '%')
            return (DIRECT);
        if (my_str_isalpha(&params[i]) || my_isnum(params[i]))
            return (INDIRECT);
        return (REGISTER);
    }
}

char get_coding_byte(char **argv)
{
    int length = array_length(argv);
    char byte_code = 0;
    params a = 0;
    int power = 7;

    for (int i = 0; argv[i]; i++) {
        a = get_params(argv[i]);
        if (a == INDIRECT) {
            byte_code += my_compute_power_it(2, power);
            byte_code += my_compute_power_it(2, power - 1);
        }
        if (a == DIRECT) {
            byte_code += my_compute_power_it(2, power);
        }
        if (a == REGISTER) {
            byte_code += my_compute_power_it(2, power - 1);
        }
        power -= 2;
    }
    return (byte_code);
}

int get_register_number(char *line)
{
    if (!line)
        return (0);
    bool found = false;
    int nbr = 0;
    for (int i = 0; line[i]; i++) {
        if (my_isnum(line[i])) {
            found = true;
        }
        if (found) {
            return (my_getnbr(&line[i]));
        }
    }
}

int write_params(corewar_t *corewar, int nbr, params params, int is_index)
{
    int size = 0;

    if (is_index && params == DIRECT)
        size = 2;
    if (!is_index && params == DIRECT)
        size = 4;
    write_little_endian(nbr, size, corewar);
}
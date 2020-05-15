/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** instruction function
*/

#include <my.h>
#include "corewar.h"

const op_t op_tab[] = {
    {"live", 0, 0, live},
    {"ld", 0, 0, ld},
    {"add", 0, 0, add},
    {"sub", 0, 0, sub},
    {"and", 0, 0, and},
    {"or", 0, 0, 0},
    {"xor", 0, 0, 0},
    {"zjmp", 0, 0, zjmp},
    {"ldi", 0, 0, 0},
    {"sti", 0, 0, sti},
    {"fork", 0, 0, 0},
    {"lld", 0, 0, 0},
    {"lldi", 0, 0, 0},
    {"lfork", 0, 0, 0},
    {"aff", 0, 0, 0},
    {"st", 0, 0, st},
    {0, 0, 0, 0}
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
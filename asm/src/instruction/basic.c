/*
** EPITECH PROJECT, 2019
** basic.c
** File description:
** basic function
*/

#include <zconf.h>
#include <my.h>
#include "corewar.h"

int live(char *line, corewar_t *corewar)
{
    char **array = str_split(&line[corewar->instr_begin] + 3, ',');
    char instruction = 1;

    write_little_endian(corewar->fd_file, instruction, 1, corewar);

    int i = 0;
    char *living_number = array[0];
    for (; living_number[i] != '%'; i++);
    int nbr = my_getnbr(&living_number[i+1]);
    write_little_endian(corewar->fd_file, nbr, 4, corewar);
}

int sti(char *line, corewar_t *corewar)
{
    char **array = str_split(&line[corewar->instr_begin] + 4, ',');
    char instruction = 11;
    char coding_byte =  get_coding_byte(array);

    write_little_endian(corewar->fd_file, instruction, 1, corewar);
    write_little_endian(corewar->fd_file, coding_byte, 1, corewar);

    write_params(corewar, get_param_value(array[0]), get_params(array[0]), 0);
    //TODO calcul cursor shift
    write_params(corewar, 15, get_params(array[1]), 1);
    write_params(corewar, get_param_value(array[2]), get_params(array[2]), 1);
}

int and(char *line, corewar_t *corewar)
{
    char **array = str_split(&line[corewar->instr_begin] + 4, ',');
    char instruction = 6;
    char coding_byte =  get_coding_byte(array);

    write_little_endian(corewar->fd_file, instruction, 1, corewar);
    write_little_endian(corewar->fd_file, coding_byte, 1, corewar);

    write_params(corewar, get_param_value(array[0]), get_params(array[0]), 0);
    write_params(corewar, get_param_value(array[1]), get_params(array[1]), 0);
    write_params(corewar, get_param_value(array[2]), get_params(array[2]), 0);
}
/*
** EPITECH PROJECT, 2019
** operator
** File description:
** operator function
*/

#include <my.h>
#include "corewar.h"

int ld(char *line, corewar_t *corewar)
{
    char **array = str_split(&line[3], ' ');
    char instruction = 2;

    write_little_endian(corewar->fd_file, instruction, 1);

    write_params(corewar, get_param_value(array[0]), get_params(array[0]), 0);
    write_params(corewar, get_param_value(array[1]), get_params(array[1]), 0);
}

int st(char *line, corewar_t *corewar)
{
    char **array = str_split(line, ' ');
    char instruction = 3;
    char coding_byte =  get_coding_byte(array);

    write_little_endian(corewar->fd_file, instruction, 1);
    write_little_endian(corewar->fd_file, coding_byte, 1);

    write_params(corewar, get_param_value(array[0]), get_params(array[0]), 0);
    write_params(corewar, get_param_value(array[1]), get_params(array[1]), 0);
}

int add(char *line, corewar_t *corewar)
{
    char **array = str_split(line, ' ');
    char instruction = 4;

    write_little_endian(corewar->fd_file, instruction, 1);
}

int sub(char *line, corewar_t *corewar)
{
    char **array = str_split(line, ' ');
    char instruction = 5;

    write_little_endian(corewar->fd_file, instruction, 1);
}
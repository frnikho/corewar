/*
** EPITECH PROJECT, 2019
** jump.c
** File description:
** jump function
*/

#include <my.h>
#include "corewar.h"

int jump(char *line, corewar_t *corewar)
{

}

int zjmp(char *line, corewar_t *corewar)
{
    char **array = str_split(&line[corewar->instr_begin] + 5, ',');
    char instruction = 9;
    shift_request_t tmp = {NULL, 0, corewar->bytes_nb, 0};
    
    write_little_endian(instruction, 1, corewar);

    if ((tmp.name = detect_shift_request(array[0])) != NULL)
        push_request(corewar, tmp.count_from, corewar->bytes_nb, tmp.name);
    write_params(corewar, get_param_value(array[0]), get_params(array[0]), 1);
    return (0);
}
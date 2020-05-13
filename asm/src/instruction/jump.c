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
    char **array = str_split(&line[corewar->instr_begin] + 3, ',');
    char instruction = 9;
    write_little_endian(corewar->fd_file, 65531, 2);
    return (0);
}
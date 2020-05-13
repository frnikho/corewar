/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser function
*/

#include <zconf.h>
#include "corewar.h"
#include "my.h"

int check_instruction(corewar_t *corewar, char *line)
{
    bool found = false;
    op_t instruction = {0};

    for (int i = 0; line[i] != 0 && !found; i++) {
        if (line[i] == ' ')
            continue;
        instruction = get_instruction(&line[i]);
        if (instruction.mnemonique != 0) {
            corewar->instr_begin = i;
            instruction.callback(line, corewar);
            corewar->instr_begin = 0;
            return (0);
        }
        found = true;
    }
}

int parse_line(corewar_t *corewar, char *line)
{
    bool comment = str_begin_char(line, '#');
    bool info = str_begin_char(line, '.');

    if (info) {
        if (str_begin(line, ".name")) {
            write_name(corewar, line);
        }
        if (str_begin(line, ".comment")) {
            write_comment(corewar, line);
        }
        if (corewar->header_count == 2) {
            write(corewar->fd_file, &corewar->header, sizeof(corewar->header));
            corewar->header_count++;
        }
        return (0);
    }

    if (comment)
        return (0);
    check_instruction(corewar, line);
}

int parser(corewar_t *corewar)
{
    if (!corewar->content)
        return (-1);
    char **array = str_split(corewar->content, '\n');
    for (int i = 0; array[i]; i++)
        parse_line(corewar, array[i]);
}
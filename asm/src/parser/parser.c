/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser function
*/

#include <zconf.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

char *get_cursor(char *line)
{
    char *result = my_strdup(line);

    for (int i = 0; result[i]; i++) {
        if (result[i] == ' ') {
            free(result);
            return (NULL);
        }
        if (result[i] == ':') {
            result[i] = '\0';
            break;
        }
    }
    return (result);
}

int check_instruction(corewar_t *corewar, char *line)
{
    bool found = false;
    op_t instruction = {0};
    char *name = NULL;

    for (int i = 0; line[i] != 0 && !found; i++) {
        if (line[i] == ' ')
            continue;
        if ((name = get_cursor(line)) != NULL)
            push_cursor(corewar, corewar->bytes_nb-1, name);
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

void write_header(corewar_t *corewar)
{
    int *tab = NULL;
    int pre_magic = 0;
    int pre_size = 0;

    tab = create_little_endian_tab(corewar->header.magic, 4);
    pre_magic = corewar->header.magic;
    corewar->header.magic = get_nb_from_bytes((int []){tab[3], \
        tab[2], tab[1], tab[0]}, 4);
    free(tab);
    tab = create_little_endian_tab(corewar->header.prog_size, 4);
    pre_size = corewar->header.prog_size;
    corewar->header.prog_size = get_nb_from_bytes((int []){tab[3], \
        tab[2], tab[1], tab[0]}, 4);
    free(tab);
    write(corewar->fd_file, &corewar->header, sizeof(corewar->header));
    corewar->header.magic = pre_magic;
    corewar->header.prog_size = pre_size;
    corewar->header_count++;
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
        if (corewar->header_count == 2)
            write_header(corewar);
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
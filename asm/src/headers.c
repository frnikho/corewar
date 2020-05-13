/*
** EPITECH PROJECT, 2019
** headers
** File description:
** headers function
*/

#include <zconf.h>
#include <my.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"

char *clean_str(char *str)
{
    int count = 0;
    char *clean = 0;
    int index = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '"')
            continue;
        count++;
    }
    clean = malloc(sizeof(char) * (count+1));
    for (int i = 0; str[i]; i++) {
        if (str[i] == '"')
            continue;
        clean[index] = str[i];
        index++;
    }
    clean[index] = 0;
    return (clean);
}

void write_name(corewar_t *corewar, char *line)
{
    char *test = clean_str(&line[6]);
    int i = 0;

    for (; test[i]; i++)
        corewar->header.prog_name[i] = test[i];
    for (; i < PROG_NAME_LENGTH + 1; i++)
        corewar->header.prog_name[i] = 0;
    corewar->header_count++;
}

void write_comment(corewar_t *corewar, char *line)
{
    char *test = clean_str(&line[9]);
    int i = 0;

    for (; test[i]; i++)
        corewar->header.comment[i] = test[i];
    for (; i < COMMENT_LENGTH + 1; i++)
        corewar->header.comment[i] = 0;
    corewar->header_count++;
}
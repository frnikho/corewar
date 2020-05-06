/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser function
*/

#include "my.h"
#include "corewar.h"

int parse_line(char *line)
{
    bool comment = str_begin_char(line, '#');

    if (comment)
        return (0);
}

int parser(char *content)
{
    if (!content)
        return (-1);
    split(content, '\n');
}
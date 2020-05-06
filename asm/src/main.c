/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    int fd = null;
    int code = null;
    char *content = null;

    if (argc != 2)
        return (84);
    fd = open_file(argv[1]);
    content = read_file(fd, argv[1]);
    code = parser(content);
    if (code == -1)
        return (84);
}
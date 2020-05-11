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
    corewar_t corewar;

    if (argc != 2)
        return (84);
    corewar.fd_file = open_file(argv[1]);
    corewar.content = read_file(corewar.fd_file, argv[1]);
    code = parser(&corewar, content);
    if (code == -1)
        return (84);
}
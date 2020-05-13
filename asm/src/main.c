/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include <fcntl.h>
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
    corewar.header_count = 0;
    corewar.header.magic = COREWAR_EXEC_MAGIC;
    corewar.header.prog_size = 23;
    corewar.fd_file = open("result.cor", O_RDWR | O_CREAT | O_TRUNC, 0666);
    code = parser(&corewar);
    if (code == -1)
        return (84);
}
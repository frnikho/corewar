/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include <fcntl.h>
#include "corewar.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <zconf.h>

int main(int argc, char **argv)
{
    int code = null;
    corewar_t corewar;

    if (argc != 2)
        return (84);
    init_corewar_struct(&corewar, argv[1]);
    code = parser(&corewar);
    if (code == -1)
        return (84);
    construct_offsets(corewar.shift_requests, corewar.cursor_shifts);
    write_offsets(corewar.shift_requests, &corewar);
    for (int i = 0; i < corewar.bytes_nb; i++)
        write(corewar.fd_file, &corewar.bytes_tab[i], 1);
}
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
    corewar.bytes_nb = 0;
    corewar.bytes_tab = malloc(sizeof(int));
    corewar.shift_requests = malloc(sizeof(shift_request_t*));
    corewar.shift_requests[0] = NULL;
    corewar.cursor_shifts = malloc(sizeof(cursor_shift_t*));
    corewar.cursor_shifts[0] = NULL;
    corewar.fd_file = open("result.cor", O_RDWR | O_CREAT | O_TRUNC, 0666);
    
    push_request(&corewar, 8, 12, "salut");
    push_request(&corewar, 0, 3, "quinze");

    push_cursor(&corewar, 0, "saluzzzt");
    push_cursor(&corewar, 19, "OOOdeux");
    push_cursor(&corewar, 14, "quinze");

    code = parser(&corewar);
    if (code == -1)
        return (84);
    for (int i = 0; i < corewar.bytes_nb; i++)
        write(corewar.fd_file, &corewar.bytes_tab[i], 1);
    
    construct_offsets(corewar.shift_requests, corewar.cursor_shifts);
    write_offsets(corewar.shift_requests, &corewar);
    
    //for (int i = 0; i < corewar.bytes_nb; i++)
    //    write(corewar.fd_file, &corewar.bytes_tab[i], 1);
}
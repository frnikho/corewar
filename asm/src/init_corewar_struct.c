/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_corewar_struct
*/

#include <fcntl.h>
#include "corewar.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <zconf.h>

void get_core_name(char **result, char *path, int *index, char *mark)
{
    if ((*result) == NULL)
        (*result) = my_strdup(path);
    for (int i = 0; (*result)[i]; i++) {
        (*result)[i] == '.' ? (*index) = 0 : 0;
        if ((*index) != -1) {
            (*result)[i] = mark[(*index)];
            (*index) ++;
        }
    }
}

char *get_output_name(char *path)
{
    char *result = NULL;
    int index = -1;
    char *mark = ".cor";
    char *bypass = NULL;

    for (int i = my_strlen(path); i >= 0; i--) {
        if (path[i] == '/') {
            result = my_strdup(&path[i+1]);
            break;
        }
    }
    get_core_name(&result, path, &index, mark);
    if (index == -1) {
        bypass = result;
        result = my_strcat(bypass, mark);
        free(bypass);
    }
    return (result);
}

int init_corewar_struct(corewar_t *corewar, char *path)
{
    char *name = get_output_name(path);

    corewar->fd_file = open_file(path);
    corewar->content = read_file(corewar->fd_file, path);
    corewar->header_count = 0;
    corewar->header.magic = COREWAR_EXEC_MAGIC;
    corewar->header.prog_size = 23;
    corewar->bytes_nb = 0;
    corewar->bytes_tab = malloc(sizeof(int));
    corewar->shift_requests = malloc(sizeof(shift_request_t*));
    corewar->shift_requests[0] = NULL;
    corewar->cursor_shifts = malloc(sizeof(cursor_shift_t*));
    corewar->cursor_shifts[0] = NULL;
    corewar->fd_file = open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
    free(name);
}
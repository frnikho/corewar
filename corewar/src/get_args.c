/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_args
*/

#include <zconf.h>
#include "vm.h"
#include <stdlib.h>
#include "my.h"

int get_args(vm_t *vm, int argc, char **argv)
{
    int index = 0;

    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-dump") == 0)
            vm->dump_cycle = 1;
        if (my_strcmp(argv[i], "-n") == 0)
            vm->prog_nbr = argv[i + 1];
        else if (my_strcmp(argv[i], "-a") == 0) {
            vm->load_address[i] = my_get_nbr(argv[i + 1]);
        } else {
            vm->prog_name[i] = argv[i];
        }
    }
}
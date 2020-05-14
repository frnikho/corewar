/*
** EPITECH PROJECT, 2019
** vm.c
** File description:
** vm function
*/

#include <zconf.h>
#include "vm.h"
#include <stdlib.h>

void load_cor_file(vm_t *vm, char *fp)
{
    int fd = open_file(fp);
    int instruction_code = 0;
    int ret = 1;

    while (ret == 1) {
        ret = read(fd, &instruction_code, 1);
        if (ret != 1)
            break;
        push_byte_vm(vm, instruction_code);
    }
}

void init_vm(char *filepath, vm_t *vm)
{
    vm->carry.flag = 0;
    vm->pc.count = 0;
    vm->bytes_nb = 0;
    vm->bytes_tab = malloc(sizeof(int));
    vm->instructions = malloc(sizeof(instruction_t *));
    vm->instructions[0] = NULL;
    init_register(vm);
    load_cor_file(vm, filepath);
    create_instructions_structs(vm);
}
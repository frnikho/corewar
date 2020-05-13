/*
** EPITECH PROJECT, 2019
** vm.c
** File description:
** vm function
*/

#include <zconf.h>
#include "corewar.h"
#include "vm.h"

void load_cor_file(vm_t *vm, char *fp)
{
    int fd = open_file(fp);
    char instruction_code = 0;

    read(fd, &instruction_code, 1);
    printf("char: %d\n", instruction_code);
}

vm_t init_vm(char *filepath)
{
    vm_t vm;
    vm.carry.flag = 0;
    vm.pc.count = 0;
    init_register(&vm);
    load_cor_file(&vm, filepath);
    return (vm);
}
/*
** EPITECH PROJECT, 2019
** register
** File description:
** register function
*/

#include "vm.h"
#include <stdlib.h>

void init_register(vm_t *vm)
{
    vm->registers = malloc(sizeof(reg_t) * (REG_NUMBER + 1));
    if (!vm->registers) {
        vm->carry.flag= ERROR_CODE;
        return;
    }
    for (int i = 0; i < REG_NUMBER; i++) {
        vm->registers->id = i;
        vm->registers->value = 0;
    }
    vm->registers[REG_NUMBER] = (reg_t){END_REGISTER_ID, END_REGISTER_VALUE};
}
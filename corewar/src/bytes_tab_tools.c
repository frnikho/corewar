/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** bytes_tab_tools
*/

#include <my.h>
#include "vm.h"
#include <stdlib.h>

void push_byte_vm(vm_t *vm, int byte)
{
    int *next_tab = malloc(sizeof(int) * (vm->bytes_nb + 1));

    if (!vm->bytes_tab)
        vm->bytes_tab = malloc(sizeof(int) * vm->bytes_nb);
    for (int i = 0; i < vm->bytes_nb; i++)
        next_tab[i] = vm->bytes_tab[i];
    next_tab[vm->bytes_nb] = byte;
    vm->bytes_nb++;
    if (vm->bytes_tab)
        free(vm->bytes_tab);
    vm->bytes_tab = next_tab;
}

params *get_params_from_binary(int *binary)
{
    params *tab = malloc(sizeof(params) * 4);
    int index = 0;

    for (int i = 0; i < 8; i += 2) {
        tab[index] = 0;
        if ((binary[i]*10 + binary[i+1]) == 1)
            tab[index] = REGISTER;
        if ((binary[i]*10 + binary[i+1]) == 10)
            tab[index] = DIRECT;
        if ((binary[i]*10 + binary[i+1]) == 11)
            tab[index] = INDIRECT;
        index++;
    }
    return (tab);
}
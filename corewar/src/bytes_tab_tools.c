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
/*
void pop_byte(vm_t *vm)
{
    int *next_tab = NULL;

    if (vm->bytes_nb <= 0 || !vm->bytes_tab)
        return;
    next_tab = malloc(sizeof(int) * (vm->bytes_nb - 1));
    for (int i = 0; i < vm->bytes_nb-1; i++)
        next_tab[i] = vm->bytes_tab[i];
    vm->bytes_nb--;
    if (vm->bytes_tab)
        free(vm->bytes_tab);
    vm->bytes_tab = next_tab;
}

void del_byte(vm_t *vm, int index)
{
    int *next_tab = NULL;
    int new_i = 0;
    int pre_nb = vm->bytes_nb;

    if (vm->bytes_nb <= 0 || !vm->bytes_tab)
        return;
    next_tab = malloc(sizeof(int) * (vm->bytes_nb));
    for (int i = 0; i < pre_nb; i++) {
        if (i != index) {
            next_tab[new_i] = vm->bytes_tab[i];
            new_i ++;
        } else
            vm->bytes_nb --;
    }
    if (vm->bytes_tab)
        free(vm->bytes_tab);
    vm->bytes_tab = next_tab;
}

void replace_byte(vm_t *vm, int index, int new_byte)
{
    if (vm->bytes_nb <= 0 || !vm->bytes_tab)
        return;
    if (index < vm->bytes_nb && index >= 0)
        vm->bytes_tab[index] = new_byte;
}

void add_byte(vm_t *vm, int index, int byte)
{
    int *next_tab = NULL;
    int new_i = 0;
    int pre_nb = vm->bytes_nb;

    if (index < -1 || index >= vm->bytes_nb)
        return;
    if (!vm->bytes_tab)
        vm->bytes_tab = malloc(sizeof(int) * vm->bytes_nb);
    next_tab = malloc(sizeof(int) * (vm->bytes_nb+1));
    if (-1 == index) {
        next_tab[new_i] = byte;
        new_i ++;
        vm->bytes_nb ++;
    }
    add_byte_core(vm, pre_nb, next_tab, (int []){index, byte, new_i});
    if (vm->bytes_tab)
        free(vm->bytes_tab);
    vm->bytes_tab = next_tab;
}
*/
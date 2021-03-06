/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main c function
*/

#include "vm.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    vm_t vm;
    int id = 0;

    if (argc < 2)
        return (EXIT_ERROR);
    init_vm(argv[1], &vm, argc);
    get_args(&vm, argc, argv);
    if (vm.carry.flag == ERROR_CODE)
        return (EXIT_ERROR);
    id = loop(&vm);
    if (id == -1)
        return (EXIT_ERROR);
}
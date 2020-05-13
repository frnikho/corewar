/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main c function
*/

#include "vm.h"

int main(int argc, char **argv)
{
    vm_t vm;
    int id = 0;

    if (argc < 2)
        return (EXIT_ERROR);
    vm = init_vm(argv[1]);
    if (vm.carry.flag == ERROR_CODE)
        return (EXIT_ERROR);
    id = loop(&vm);
    if (id == -1)
        return (EXIT_ERROR);
}
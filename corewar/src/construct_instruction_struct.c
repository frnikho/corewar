/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** construct_instruction_struct
*/

#include "vm.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include "op.h"

op_t op_tab[] =
    {
        {"live", 1, {T_DIR}, 1, 10, NULL},
        {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, NULL},
        {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, NULL},
        {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, NULL},
        {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, NULL},
        {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 0},
        {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 0},
        {"zjmp", 1, {T_DIR}, 9, 20, NULL},
        {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,0},
        {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,NULL},
        {"fork", 1, {T_DIR}, 12, 800, 0},
        {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 0},
        {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,0},
        {"lfork", 1, {T_DIR}, 15, 1000, 0},
        {"aff", 1, {T_REG}, 16, 2, 0},
        {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, NULL},
        {0, 0, {0}, 0, 0, 0}
    };

int get_instruction(int byte_code)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (op_tab[i].code == byte_code)
            return (i);
    }
    return (0);
}

int count_next_instruction_jump(params *tab)
{
    // Count next number of bytes to jump to the next instruction
    // by using the prameters type
    return (0);
}

void add_instruction_to_tab(instruction_t ***tab, instruction_t *ins)
{
    instruction_t **next_tab = NULL;
    int len = 0;

    for (len = 0; (*tab)[len]; len++);
    next_tab = malloc(sizeof(instruction_t *) * (len+2));
    for (int i = 0; (*tab)[i]; i++)
        next_tab[i] = (*tab)[i];
    next_tab[len] = ins;
    next_tab[len+1] = NULL;
    free((*tab));
    (*tab) = next_tab;
}

instruction_t *construct_instruction(vm_t *vm, int ins_indx, int byte_indx)
{
    instruction_t *ins = malloc(sizeof(instruction_t));

    ins->instruction_code = vm->bytes_tab[byte_indx];
    if (op_tab[ins_indx].nbr_args != 1) {
        ins->coding_byte = byte_to_binary(vm->bytes_tab[byte_indx+1]);
        ins->parameters = get_params_from_binary(ins->coding_byte);
    } else {
        ins->coding_byte = byte_to_binary(0);
        ins->parameters = malloc(sizeof(params) * 4);
        for (int i = 0; i < 4; i++)
            ins->parameters[i] = 0;  
    }
    printf("Instruction %i    %i %i %i\n", ins->instruction_code, ins->parameters[0], ins->parameters[1], ins->parameters[2]);
    return (ins);
}

void create_instructions_structs(vm_t *vm)
{
    int ins_index = -1;
    instruction_t *new_ins = NULL;

    for (int i = 0; i < vm->bytes_nb; i++) {
        if ((ins_index = get_instruction(vm->bytes_tab[i])) != 0) {
            new_ins = construct_instruction(vm, ins_index, i);
            add_instruction_to_tab(&vm->instructions, new_ins);
            i += count_next_instruction_jump(new_ins->parameters);
        }
    }
}
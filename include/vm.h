/*
** EPITECH PROJECT, 2019
** vm.h
** File description:
** header file
*/

#ifndef VM_H
#define VM_H

#define REG_NUMBER 16
#define END_REGISTER_ID 500
#define END_REGISTER_VALUE END_REGISTER_ID

#define ERROR_CODE -1
#define EXIT_ERROR 84
#define EXIT_NORMAL 0

typedef struct carry_s {
    int flag;
} carry_t;

typedef struct pc_s {
    int count;
} pc_t;

typedef struct reg_s {
    int id;
    int value;
} reg_t;

typedef struct vm_s {
    reg_t *registers;
    pc_t pc;
    carry_t carry;
    int *bytes_tab;
    int bytes_nb;
} vm_t;

void init_vm(char *filepath, vm_t *vm);
void init_register(vm_t *vm);
int loop(vm_t *vm);

int get_nb_from_bytes(int *bytes, int bytes_nb);
int get_nb_from_tab_index(int *tab, int index, int bytes_nb);

void push_byte_vm(vm_t *vm, int byte);
//void pop_byte(vm_t *vm);
//void del_byte(vm_t *vm, int index);
//void replace_byte(vm_t *vm, int index, int new_byte);
//void add_byte(vm_t *vm, int index, int byte);
//void add_byte_core(vm_t *vm, int pre_nb, int *next_tab, int *values);

#endif

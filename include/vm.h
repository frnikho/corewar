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
    char *content;
} vm_t;

vm_t init_vm(char *filepath);
void init_register(vm_t *vm);
int loop(vm_t *vm);

#endif

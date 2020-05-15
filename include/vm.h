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

#define null 0

typedef enum {false, true } bool;
typedef enum {REGISTER = 1, DIRECT = 2, INDIRECT = 3} params;

typedef struct instruction_s {
    int instruction_code;
    int *coding_byte;
    params *parameters;
} instruction_t;

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
    int dump_cycle;
    char **prog_name;
    int *prog_nbr;
    int *load_address;
    instruction_t **instructions;
} vm_t;

int open_file(char *content);
void init_vm(char *filepath, vm_t *vm, int argc);
void init_register(vm_t *vm);
int loop(vm_t *vm);

void push_byte_vm(vm_t *vm, int byte);
int get_nb_from_bytes(int *bytes, int bytes_nb);
int get_nb_from_tab_index(int *tab, int index, int bytes_nb);
int *byte_to_binary(int byte);
params *get_params_from_binary(int *binary);

void create_instructions_structs(vm_t *vm);


#endif

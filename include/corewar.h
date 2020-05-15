/*
** EPITECH PROJECT, 2020
** corwar.h
** File description:
** corwar function
*/

#ifndef CORWAR_COREWAR_H
#define CORWAR_COREWAR_H

#include "op.h"
#include <stdio.h>

#define null 0

typedef enum {false, true } bool;
typedef enum {REGISTER = 1, DIRECT = 2, INDIRECT = 3} params;

int parser(corewar_t *corewar);
void get_core_name(char **result, char *path, int *index, char *mark);
char *get_output_name(char *path);
int init_corewar_struct(corewar_t *corewar, char *path);

int open_file(char *content);
char *read_file(int fd, char *fp);
void write_little_endian(int nb, int bytes_nb, corewar_t *corewar);
int *create_little_endian_tab(int nb, int bytes_nb);
void write_little_endian_fd(int fd, int nb, int bytes_nb, corewar_t *corewar);
int get_nb_from_bytes(int *bytes, int bytes_nb);

bool str_begin(const char *str, char const *begin);
bool str_begin_char(const char *str, char c);

char **split(char *content, char c);

op_t get_instruction(char *name);

int get_param_value(char *param);
char *detect_shift_request(char *str);

int live(char *line, corewar_t *corewar);
int sti(char *line, corewar_t *corewar);
int and(char *line, corewar_t *corewar);
int zjmp(char *line, corewar_t *corewar);
int ld(char *line, corewar_t *corewar);
int st(char *line, corewar_t *corewar);
int add(char *line, corewar_t *corewar);
int sub(char *line, corewar_t *corewar);

params get_params(char *params);
int get_register_number(char *line);
char get_coding_byte(char **argv);
int write_params(corewar_t *corewar, int nbr, params params, int is_index);

void write_name(corewar_t *corewar, char *line);
void write_comment(corewar_t *corewar, char *line);

void push_byte(corewar_t *corewar, int byte);
void pop_byte(corewar_t *corewar);
void del_byte(corewar_t *corewar, int index);
void replace_byte(corewar_t *corewar, int index, int new_byte);
void add_byte(corewar_t *corewar, int index, int byte);
void add_byte_core(corewar_t *corewar, int pre_nb, int *next_tab, int *values);

void push_request(corewar_t *corewar, int count_from, int index, char *name);
void push_cursor(corewar_t *corewar, int position, char *name);
int calc_request_offset(shift_request_t *request, cursor_shift_t **cursors);
void construct_offsets(shift_request_t **requests, cursor_shift_t **cursors);
void write_offsets(shift_request_t **requests, corewar_t *corewar);

#endif
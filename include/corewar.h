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

typedef enum { false, true } bool;

int parser(corewar_t *corewar, char *content);

int open_file(char *content);
char *read_file(int fd, char *fp);

bool str_begin(const char *str, char const *begin);
bool str_begin_char(const char *str, char c);

char **split(char *content, char c);

op_t get_instruction(char *name);

int live(char *line, corewar_t *corewar);
int sti(char *line, corewar_t *corewar);
int and(char *line, corewar_t *corewar);
int zjmp(char *line, corewar_t *corewar);

#endif
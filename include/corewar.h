/*
** EPITECH PROJECT, 2020
** corwar.h
** File description:
** corwar function
*/

#ifndef CORWAR_COREWAR_H
#define CORWAR_COREWAR_H

#define null 0

typedef enum { false, true } bool;

int parser(char *content);

int open_file(char *content);
char *read_file(int fd, char *fp);

int str_begin(const char *str, char const *begin);
bool str_begin_char(const char *str, char c);

char **split(char *content, char c);

#endif
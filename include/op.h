/*
** EPITECH PROJECT, 2020
** op.h
** File description:
** op header file
*/

#ifndef _OP_H_
# define _OP_H_

#define MEM_SIZE (6*1024)
#define IDX_MOD 512
#define MAX_ARGS_NUMBER 4

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

typedef char args_type_t;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

#define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct shift_request_s
{
    char *name;
    int index;
    int count_from;
    int offset;
} shift_request_t;

typedef struct cursor_shift_s
{
    char *name;
    int position;
} cursor_shift_t;

typedef struct header_name_s
{
    //int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    //int prog_size;
    //char comment[COMMENT_LENGTH + 1];
} header_name_t;

typedef struct header_com_s
{
    //int magic;
    //char prog_name[PROG_NAME_LENGTH + 1];
    //int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_com_t;

typedef struct header_s
{
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct corewar_s {
    char *content;
    int fd_file;
    int current_write_size;
    int instr_begin;
    int cursor;
    header_t header;
    int header_count;
    int *bytes_tab;
    int bytes_nb;
    shift_request_t **shift_requests;
    cursor_shift_t **cursor_shifts;
} corewar_t;

typedef struct op_s
{
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    int (*callback)(char *line, corewar_t *corewar);
} op_t;

#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE DIR_SIZE

extern op_t op_tab[];

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#endif
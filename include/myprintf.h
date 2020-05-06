/*
** EPITECH PROJECT, 2019
** myprintf.h
** File description:
** header file
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H
#include <stdarg.h>

void my_printf(char const *str, ...);

void display_unsigned_int(va_list ap);
void display_s_my_printf(char const *str);

int my_printf_d_flags(char const *str, int index, int nbr);
int my_printf_nbr_params(char const *str, int index);
int my_printf_get_length(char const *str, int index, va_list ap);

#endif
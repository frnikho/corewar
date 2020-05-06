/*
** EPITECH PROJECT, 2019
** str_start_with.c
** File description:
** str_srart_with function
*/

#include "my.h"
#include "myprintf.h"

int str_start_with(char *str, char *start_with)
{
    for (int i = 0; start_with[i] != 0 && str[i] != 0; i++) {
        if (start_with[i] != str[i])
            return (0);
    }
    return (1);
}
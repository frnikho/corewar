/*
** EPITECH PROJECT, 2019
** my_strerr.c
** File description:
** my_strerr function
*/

#include "my.h"
#include <unistd.h>

void my_strerr(char *str)
{
    write(2, str, my_strlen(str));
}
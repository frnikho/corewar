/*
** EPITECH PROJECT, 2020
** str_begin.c
** File description:
** str begin function
*/

#include <corewar.h>

bool str_begin_char(const char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            continue;
        if (str[i] == c)
            return (true);
        else
            return (false);
    }
    return (false);
}

bool str_begin(const char *str, char const *begin)
{
    for (int i = 0; begin[i] && str[i]; i++) {
        if (begin[i] != str[i])
            return (false);
    }
    return (true);
}
/*
** EPITECH PROJECT, 2020
** str_begin.c
** File description:
** str begin function
*/

#include <corewar.h>

static bool same_string(char const *str1, char const *str2)
{

}

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

int str_begin(const char *str, char const *begin)
{

}
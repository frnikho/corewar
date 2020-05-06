/*
** EPITECH PROJECT, 2019
** str_is_equals.c
** File description:
** str_is_equals function
*/

#include "my.h"

static int is_equals(char const *longest, char const *shortest)
{
    for (int i = 0; longest[i] != 0; i++) {
        if (longest[i] == shortest[i])
            continue;
        else
            return (0);
    }
    return (1);
}

int str_is_equals(char const *str1, char const *str2)
{
    if (!str1 || !str2)
        return (-1);
    int length_1 = my_strlen(str1);
    int length_2 = my_strlen(str2);

    if (length_1 >= length_2) {
        return (is_equals(str1, str2));
    } else {
        return (is_equals(str2, str1));
    }
}
/*
** EPITECH PROJECT, 2019
** str_contains.c
** File description:
** str_contains
*/

#include "my.h"

int str_contains(char *str, char *word)
{
    int y = 0;
    int word_length = my_strlen(word);

    for (int i = 0; str[i] != 0; i++) {
        if (y == word_length)
            return (1);
        if (str[i] == word[y]) {
            y++;
            continue;
        } else {
            y = 0;
        }
    }
    return (0);
}
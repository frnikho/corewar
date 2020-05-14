/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** strdup function
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *str)
{
    int length = my_strlen(str);
    char *result = malloc(length+1);
    my_strcpy(result, str);
    return (result);
}
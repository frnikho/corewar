/*
** EPITECH PROJECT, 2019
** str_cat.c
** File description:
** strcat function
*/

#include <stdlib.h>
#include "my.h"

char *str_cat(char *one, char *two)
{
    int length_1 = my_strlen(one);
    int length_2 = my_strlen(two);
    char *result = malloc((sizeof(char) * (length_1 + length_2 + 1)));
    int index = 0;

    for (int i = 0; one[i] != 0; i++) {
        result[index] = one[i];
        index++;
    }
    for (int i = 0; two[i] != 0; i++) {
        result[index] = two[i];
        index++;
    }
    result[length_1 + length_2] = 0;
    return (result);
}

char *str_cat_char(char *one , char c)
{
    char *result = malloc(sizeof(char) * (my_strlen(one) + 2));

    int index = 0;
    for (int i = 0; one[i] != 0; i++) {
        result[index] = one[i];
        index++;
    }
    result[index] = c;
    result[index+1] = 0;

    return (result);
}
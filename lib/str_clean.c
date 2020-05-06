/*
** EPITECH PROJECT, 2019
** str_clean
** File description:
** str_clean function
*/

#include <stdlib.h>
#include "my.h"

char *str_clean(char *str)
{
    if (!str)
        return (0);
    char *result = malloc(my_strlen(str));
    int index = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 33 && str[i] <= 126) {
            result[index] = str[i];
            index++;
        }
    }
    result[index] = 0;
    return (result);
}
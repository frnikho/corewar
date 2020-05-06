/*
** EPITECH PROJECT, 2019
** str_array.c
** File description:
** str_array function
*/

#include "my.h"
#include <stdlib.h>

int array_length(char **array)
{
    int i = 0;

    for (; array[i] != 0; i++)
        continue;
    return (i);
}

char **str_array(char *str)
{
    if (str == 0) return (0);
    int length = my_strlen(str);
    char **array = malloc(sizeof(char*) * (length + 1));
    for (int i = 0; i < length; i++)
        array[i] = malloc(sizeof(char*) * (length + 1));
    int index = 0;
    int y = 0;
    int found = 0;
    for (int i = 0; str[i] != 0 && str[i] != '\n'; i++, y++) {
        str[i] >= 33 && str[i] <= 126 ? found = 1 : 0;
        if (str[i] == ' ' && found) {
            index++;
            y = -1;
            found = 0;
            continue;
        }
        array[index][y] = str[i];
    }
    array[index+1] = 0;
    return (array);
}

char **str_array_key(char *str, char key)
{
    if (str == 0) return (0);
    int length = my_strlen(str);
    char **array = malloc(sizeof(char*) * (length + 1));
    for (int i = 0; i < length; i++)
        array[i] = malloc(sizeof(char*) * (length + 1));
    int index = 0;
    int y = 0;
    int found = 0;
    for (int i = 0; str[i] != 0; i++, y++) {
        str[i] >= 33 && str[i] <= 126 ? found = 1 : 0;
        if (str[i] == key && found) {
            index++;
            y = -1;
            found = 0;
            continue;
        }
        array[index][y] = str[i];
    }
    array[index+1] = 0;
    return (array);
}
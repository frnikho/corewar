/*
** EPITECH PROJECT, 2020
** split.c
** File description:
** split function
*/

#include <stdlib.h>

int count_line(const char *content, char split)
{
    if (!content)
        return (-1);
    int count = 0;
    for (int i = 0; content[i] != 0; i++)
        if (content[i] == split)
            count++;
    return (count);
}

int count_character_line(const char *content, char split, int line)
{
    int count_char = 0;
    int count_line = 0;
    for (int i = 0; content[i] != 0; i++) {
        if (content[i] == split) {
            count_line++;
            i++;
        }
        if (count_line == line)
            count_char++;
    }
    return (count_char+1);
}

char **split(char *content, char c)
{
    int length = count_line(content, c);
    char **array = malloc(sizeof(char*) * (length + 1));
    for (int i = 0; i < length; i++)
        array[i] = malloc(count_character_line(content, c, i));

    for (int i = 0; content[i]; i++) {

    }

    array[length] = 0;
}
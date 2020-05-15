/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** cat two string together
*/

#include <stdlib.h>

int my_strlen(char const *str);
void my_putchar(char c);
void my_put_nbr(int nb);

char *my_strcat(char *dest, char const *src)
{
    int size = 0;
    int y = 0;

    char *result =
    malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (int i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[i];
        size++;
    }
    for (y = 0; src[y] != '\0'; y++) {
        result[size + y] = src[y];
    }
    result[size + y] = '\0';
    return (result);
}
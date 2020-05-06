/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** 
*/

#include "my.h"
#include <stdlib.h>

void *my_putnbr_base(int nbr, char const *base)
{
    int power = my_strlen(base);
    int length = get_int_length(nbr);
    char *result = malloc(length);
    int index = 0;

    if (nbr < 0)
        nbr *= -1;
    while (nbr > power) {
        result[index] = base[nbr % power];
        nbr /= power;
        index++;
    }
    result[index] = base[nbr];
    result = my_revstr(result);
    return (result);
}
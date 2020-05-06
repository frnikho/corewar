/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert a string into a number
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int coef = 0;
    int count = 0;
    int index = 0;

    while (my_isnum(str[index])) {
        count++;
        index++;
    }
    coef = my_compute_power_it(10, count-1);
    for (int i = 0; i < count; i++) {
        result += (str[i] - 48) * coef;
        coef /= 10;
    }
    return (result);
}

int my_getnbr_index(char const *str, int start_index)
{
    int result = 0;
    int coef = 0;
    int count = 0;
    int index = start_index;

    while (my_isnum(str[index])) {
        count++;
        index++;
    }
    coef = my_compute_power_it(10, count - 1);
    for (int i = start_index; i < count; i++) {
        result += (str[i] - 48) * coef;
        coef /= 10;
    }
    result += (str[count] - 48) * coef;

    return (result);
}
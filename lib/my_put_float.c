/*
** EPITECH PROJECT, 2019
** my_put_float
** File description:
** show float number
*/

#include "my.h"

void my_put_float(float nbr)
{
    my_put_nbr(nbr);
    int integer = (int) nbr;
    my_putchar('.');
    int a = ((nbr - integer) * 1000000);
    my_put_nbr(a);
}

void my_put_nfloat(float nbr, int length)
{
    my_put_nbr(nbr);
    int integer = (int) nbr;
    my_putchar('.');
    int a = ((nbr - integer) * my_compute_power_it(10, length));
    my_put_nbr(a);
}
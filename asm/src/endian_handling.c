/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_handling.c
*/

#include <unistd.h>
#include <stdlib.h>

int get_biggest_power(int nb, int base)
{
    long int total = 1;
    int result = 0;

    if (nb < base)
        return (0);
    while (total <= nb) {
        result += 1;
        total *= base;
    }
    return (result-1);
}

static int calc_and_print(int nb, int fd, int *tab, int reset)
{
    static int bytes = 0;
    int digit = (nb/256);

    if (reset == 1)
        bytes = 0;
    if (nb < 256) {
        tab[bytes] = nb;
        bytes ++;
        return (bytes);
    }
    if (digit >= 256)
        calc_and_print(digit, fd, tab, 0);
    else {
        tab[bytes] = digit;
        bytes ++;
    }
    calc_and_print(nb - (digit * 256), fd, tab, 0);
    return (bytes);
}

void write_little_endian(int fd, int nb, int bytes_nb)
{
    int zero = 0;
    int *tab = malloc(sizeof(int) * bytes_nb);
    int bytes = 0;

    if (nb < 0) {
        nb = (nb * -1) - 1;
        calc_and_print(nb, fd, tab, 1);
        for (int i = 0; i < bytes_nb; i++)
            tab[i] = 255 - tab[i];
        zero = 255;
        bytes = get_biggest_power(nb, 256)+1;
    } else {
        calc_and_print(nb, fd, tab, 1);
        bytes = get_biggest_power(nb, 256)+1;
    }
    for (int i = bytes; i < bytes_nb; i++)
        write(fd, &zero, 1);
    for (int i = 0; i < bytes; i++)
        write(fd, &tab[i], 1);
    free(tab);
}
/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_handling.c
*/

#include "corewar.h"
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

static int calc_and_print(int nb, int *tab, int reset)
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
        calc_and_print(digit, tab, 0);
    else {
        tab[bytes] = digit;
        bytes ++;
    }
    calc_and_print(nb - (digit * 256), tab, 0);
    return (bytes);
}

void write_little_endian(int nb, int bytes_nb, corewar_t *corewar)
{
    int zero = 0;
    int *tab = malloc(sizeof(int) * bytes_nb);
    int bytes = 0;

    if (nb < 0) {
        nb = (nb * -1) - 1;
        calc_and_print(nb, tab, 1);
        for (int i = 0; i < bytes_nb; i++)
            tab[i] = 255 - tab[i];
        zero = 255;
        bytes = get_biggest_power(nb, 256)+1;
    } else {
        calc_and_print(nb, tab, 1);
        bytes = get_biggest_power(nb, 256)+1;
    }
    for (int i = bytes; i < bytes_nb; i++)
        push_byte(corewar, zero);
    for (int i = 0; i < bytes; i++)
        push_byte(corewar, tab[i]);
    free(tab);
}

static void create_result_tab(int *tab_result, int *tab, int *values)
{
    int index = 0;

    for (int i = values[0]; i < values[1]; i++) {
        tab_result[index] = values[2];
        index ++;
    }
    for (int i = 0; i < values[0]; i++) {
        tab_result[index] = tab[i];
        index++;
    }
    free(tab);
}

int *create_little_endian_tab(int nb, int bytes_nb)
{
    int zero = 0;
    int *tab = malloc(sizeof(int) * bytes_nb);
    int *result = malloc(sizeof(int) * bytes_nb);
    int bytes = 0;

    if (nb < 0) {
        nb = (nb * -1) - 1;
        calc_and_print(nb, tab, 1);
        for (int i = 0; i < bytes_nb; i++)
            tab[i] = 255 - tab[i];
        zero = 255;
        bytes = get_biggest_power(nb, 256)+1;
    } else {
        calc_and_print(nb, tab, 1);
        bytes = get_biggest_power(nb, 256)+1;
    }
    create_result_tab(result, tab, (int []){bytes, bytes_nb, zero});
    return (result);
}

void write_little_endian_fd(int fd, int nb, int bytes_nb, corewar_t *corewar)
{
    int zero = 0;
    int *tab = malloc(sizeof(int) * bytes_nb);
    int bytes = 0;

    if (nb < 0) {
        nb = (nb * -1) - 1;
        calc_and_print(nb, tab, 1);
        for (int i = 0; i < bytes_nb; i++)
            tab[i] = 255 - tab[i];
        zero = 255;
        bytes = get_biggest_power(nb, 256)+1;
    } else {
        calc_and_print(nb, tab, 1);
        bytes = get_biggest_power(nb, 256)+1;
    }
    for (int i = bytes; i < bytes_nb; i++)
        write(fd, &zero, 1);
    for (int i = 0; i < bytes; i++)
        write(fd, &tab[i], 1);
    free(tab);
}

int power(int nb, int power)
{
    int result = 1;

    if (power == 0)
        return (1);
    for (int i = 0; i < power; i++)
        result *= nb;
    return (result);
}

int get_nb_from_bytes(int *bytes, int bytes_nb)
{
    int result = 0;
    int sign_cap[] = {127, 32767, 8388607, 2147483647};

    if (bytes_nb > 4 || bytes_nb < 1)
        return (0);
    for (int i = 0; i < bytes_nb - 1; i++)
        result += bytes[i] * power(256, bytes_nb - i - 1);
    result += bytes[bytes_nb-1];
    if (result > sign_cap[bytes_nb-1]) {
        for (int i = 0; i < bytes_nb; i++)
            bytes[i] = bytes[i] - 255;
        bytes[bytes_nb-1] -= 1;
        return (get_nb_from_bytes(bytes, bytes_nb));
    }
    return (result);
}
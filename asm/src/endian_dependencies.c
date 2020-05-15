/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_dependencies
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int power(int nb, int power)
{
    int result = 1;

    if (power == 0)
        return (1);
    for (int i = 0; i < power; i++)
        result *= nb;
    return (result);
}

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

void construct_offsets(shift_request_t **requests, cursor_shift_t **cursors)
{
    for (int i = 0; requests[i]; i++) {
        requests[i]->offset = calc_request_offset(requests[i], cursors);
    }
}
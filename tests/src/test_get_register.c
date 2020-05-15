/*
** EPITECH PROJECT, 2019
** test_get_register
** File description:
** unit tests
*/

#include "corewar.h"
#include <criterion/criterion.h>

Test(get_register_number, r1_number)
{
    char *line = "r1";
    int number = get_register_number(line);
    cr_expect_eq(number, 1);
}

Test(get_register_number, wrong_number)
{
    char *line = "azerty:)";
    int number = get_register_number(line);
    cr_expect_eq(number, 0);
}

Test(get_register_number, big_number)
{
    char *line = "r24856";
    int number = get_register_number(line);
    cr_expect_eq(number, 24856);
}

Test(get_register, number)
{
    char *line = "1e3e7a7";
    int number = get_register_number(line);
    cr_expect_eq(number, 1);
}

Test(get_register, empty)
{
    int number = get_register_number("");
    cr_expect_eq(number, 0);
}

Test(get_register, null)
{
    int number = get_register_number(0);
    cr_expect_eq(number, 0);
}
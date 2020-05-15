/*
** EPITECH PROJECT, 2019
** test_get_params.c
** File description:
** get params
*/

#include "corewar.h"
#include "op.h"
#include "my.h"
#include <criterion/criterion.h>

Test(get_params, register_r1)
{
    params p = get_params("r1");
    cr_expect_eq(p, REGISTER);
}

Test(get_params, direct)
{
    params p = get_params("410");
    cr_expect_eq(p, INDIRECT);
}

Test(get_params, indirect)
{
    params p = get_params("%:live");
    cr_expect_eq(p, DIRECT);
}
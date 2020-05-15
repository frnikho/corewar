/*
** EPITECH PROJECT, 2019
** write little endian
** File description:
** unit tests
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <my.h>

Test(get_coding_byte, pdf_and)
{
    char *params = "r1,%:40,r1";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 100);
}

Test(get_coding_byte, pdf_sti)
{
    char *params = "r1,%:40,%1";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 104);
}

Test(get_coding_byte, one_argv)
{
    char *params = "r1";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 64);
}

Test(get_coding_byte, two_argv)
{
    char *params = "r1,%:hello";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 96);
}

Test(get_coding_byte, three_argv)
{
    char *params = "r1,r2,%:hello";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 88);
}

Test(get_coding_byte, four_argv)
{
    char *params = "r1,%10,%:live,r4";
    char **array = str_split(params, ',');
    int char_code = get_coding_byte(array);
    cr_expect_eq(char_code, 105);
}
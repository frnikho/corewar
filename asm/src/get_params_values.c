/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** get_params_values
*/

#include <my.h>
#include "corewar.h"

int get_param_value(char *param)
{
    params param_type = get_params(param);
    int i = 0;

    if (param_type == REGISTER)
        return (get_register_number(param));
    if (param_type == INDIRECT)
        return (my_getnbr(param));
    if (param_type == DIRECT) {
        for (i = 0; param[i] != '%'; i++);
        param = &param[i+1];
        return (my_getnbr(param));
    }
    return (-1);
}
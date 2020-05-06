/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printf function
*/

#include "my.h"
#include "myprintf.h"

int is_my_printf_value(char const *str, int index)
{
    char tabs[13] = {'c', 's', 'd', 'o', 'x', 'b', 'p', 'P', 'S',
        'u', '%', 'f', '.'};
    if (str[index + 1] == 'l' && str[index + 2] == 'f')
        return (2);
    for (int i = 0; i <= 14; i++) {
        if (str[index + 1] == '.' && my_isnum(str[index + 2])
        && str[index + 3] == tabs[i]) {
            return (3);
        }
        if (str[index + 1] == tabs[i])
            return (1);
    }

    return (0);
}

void my_printf_flags(char const *str, int index, va_list ap)
{
    int nbr = str[index + 2] - 48;
    if (str[index + 3] == 'f')
        my_put_nfloat(va_arg(ap, double), nbr);

}

void my_printf_check_type_1(char const *str, int index, va_list ap)
{
    if (str[index + 1] == 's') my_putstr(va_arg(ap, char*));
    if (str[index + 1] == 'd' || str[index + 1] == 'i')
        my_put_nbr(va_arg(ap, int));
    if (str[index + 1] == 'c') my_putchar(va_arg(ap, int));
    if (str[index + 1] == 'x')
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
    if (str[index + 1] == 'b') my_putstr(my_putnbr_base(va_arg(ap, int), "01"));
    if (str[index + 1] == 'S') display_s_my_printf(va_arg(ap, char*));
    if (str[index + 1] == 'P')
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
    if (str[index + 1] == 'p') {
        my_putstr("0x");
        my_putstr(my_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
    }
    if (str[index + 1] == 'u') display_unsigned_int(ap);
    if (str[index + 1] == '%') my_putchar('%');
    if (str[index + 1] == 'f') my_put_float(va_arg(ap, double));
}

static void display_printf_flags(char const *str, int *i, va_list ap)
{
    int nb = is_my_printf_value(str, *i);
    nb += my_printf_get_length(str, *i, ap);
    if (nb == 3)
        my_printf_flags(str, *i, ap);
    else if (nb != 0)
        my_printf_check_type_1(str, *i, ap);
    else
        my_putchar('%');
    *i += nb;
}

void my_printf(char const *str, ...)
{
    va_list ap;
    va_start(ap, 0);

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '%' && str[i+1] != 0) {
            display_printf_flags(str, &i, ap);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
}

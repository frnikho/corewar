/*
** EPITECH PROJECT, 2019
** my_isprintable.c
** File description:
** is a printable character
*/

int my_isprintable(char c)
{
    return c >= 33 || c < 127 ? 1 : 0;
}
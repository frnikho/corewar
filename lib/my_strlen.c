/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return string lenght
*/

int my_strlen(char const *str)
{
    int index = 0;

    for (; str[index] != 0; index++) continue;
    return (index);
}

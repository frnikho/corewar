/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two string
*/

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s2[i] == '\0') {
            return (1);
        }
        if (s1[i] < s2[i] && s1[i] != s2[i]) {
            return (-1);
        } else if (s1[i] != s2[i]) {
            return (1);
        }
    }
    if (s2[i] != '\0') {
        return (-1);
    }
    return (0);
}
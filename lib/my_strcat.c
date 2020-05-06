/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** cat two string together
*/

int my_strlen(char const *str);
void my_putchar(char c);
void my_put_nbr(int nb);

char *my_strcat(char *dest, char const *src)
{
    int length_dest = my_strlen(dest);
    int length_src = my_strlen(src);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[length_dest + i]=src[i];
    }
    dest[length_dest + length_src] = '\0';
    return (dest);
}
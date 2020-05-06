/*
** EPITECH PROJECT, 2020
** read_file.c
** File description:
**  function
*/

#include <zconf.h>
#include <stdlib.h>
#include <fcntl.h>

int open_file(char *content)
{
    int fd = open(content, O_RDWR);
    if (fd <= 1)
        return (-1);
    return (fd);
}

char *read_file(int fd, char *fp)
{
    char *buffer = malloc(sizeof(char) * (1024*1024));
    int size = 0;
    while (((read(fd, buffer, 1)) > 0))
        size++;
    close(fd);
    free(buffer);
    fd = open_file(fp);
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size-1] = 0;
    close(fd);
    return (buffer);
}
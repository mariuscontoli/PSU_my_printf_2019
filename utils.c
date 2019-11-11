/*
** EPITECH PROJECT, 2019
** utility functions file
** File description:
** regroup used functions for this project
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        ++i;
    }
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    if (str[0] == '-' && str[1])
        i++;
    for (; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9'))
            return (nbr);
        nbr *= 10;
        nbr += str[i] - 48;
    }
    if (str[0] == '-')
        return (-1 * nbr);
    else {
        return nbr;
    }
}
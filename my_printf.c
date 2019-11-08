/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** This is our own print function.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_printf.h"

typedef struct PTR {
    char flag;
    void (*ptr)(va_list ap);
} PTR;

PTR flags[] = {
        {'c', &print_char},
        {'s', &print_str},
        {'d', &print_nbr},
        {'i', &print_nbr},
        {'\0', NULL}};

void print_char(va_list ap)
{
    char charac;
    charac = va_arg(ap, int);
    my_putchar(charac);
}

void print_str(va_list ap)
{
    char *str;
    str = va_arg(ap, char *);
    if (str != NULL){
        my_putstr(str);
    }
}

void print_nbr(va_list ap)
{
    int nb;
    nb = va_arg(ap, int);
    my_put_nbr(nb);
}

void no_flag(char *s, int i, int temp)
{
    if (temp == 0) {
        my_putchar('%');
        my_putchar(s[i]);
    }
}

void is_flag(char *s, int temp, va_list ap)
{
    for (int i = 0; s[i] != '\0'; i++) {
        temp = 0;
        if (s[i] == '%') {
            i++;
            for (int y = 0; flags[y].flag != '\0'; y++) {
                if (s[i] == flags[y].flag ) {
                    flags[y].ptr(ap);
                    temp = 1;
                }
            }
            no_flag(s, i, temp);
        } else {
            my_putchar(s[i]);
        }
    } 
}

void my_printf(char *s, ...)
{
    va_list ap;
    int temp;

    va_start(ap, s);
    is_flag(s, temp, ap);
    va_end(ap);
}
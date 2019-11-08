/*
** EPITECH PROJECT, 2019
** header
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
void my_putchar(char c);
void print_str(va_list ap);
void print_char(va_list ap);
void print_nbr(va_list ap);
void my_printf(char *s, ...);
void is_flag(char *s, int temp, va_list ap);
void no_flag(char *s, int i, int temp);

#endif
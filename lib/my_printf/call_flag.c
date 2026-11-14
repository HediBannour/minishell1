/*
** EPITECH PROJECT, 2023
** call_flag
** File description:
** my_printf
*/

#include "./include/my.h"
#include <stdio.h>
#include <stdarg.h>

void call_flag(const char *format, int b, va_list list)
{
    if (format[b] == 'd' || format[b] == 'i') {
        my_put_nbr(va_arg(list, int));
    }
    if (format[b] == 'c') {
        my_putchar(va_arg(list, int));
    }
    if (format[b] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (format[b] == 'u') {
        u_unsigned(va_arg(list, long));
    }
    if (format[b] == 'o') {
        octal(va_arg(list, unsigned int));
    }
    if (format[b] == 'x') {
        hexa_tiny(va_arg(list, unsigned int));
    }
    call_flag2(format, b, list);
}

void call_flag2(const char *format, int b, va_list list)
{
    if (format[b] == 'X') {
        hexa_capital(va_arg(list, unsigned int));
    }
    if (format[b] == 'f') {
        float_dis(va_arg(list, double));
    }
    if (format[b] == 'F') {
        float_dis(va_arg(list, double));
    }
    if (format[b] == 'e') {
        scientific_notation_tiny(va_arg(list, double));
    }
    if (format[b] == 'E') {
        scientific_notation_capital(va_arg(list, double));
    }
}

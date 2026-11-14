/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Projet
*/

#include "./include/my.h"
#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list list;
    int b = 0;

    va_start(list, format);
    while (format[b] != '\0') {
        if (format[b] == '%' && format[b + 1] == '%') {
            my_putchar('%');
        }
        if (format[b] == '%') {
            call_flag(format, b + 1, list);
            b++;
        } else {
            my_putchar(format[b]);
        }
        b++;
    }
    va_end(list);
}

/*
** EPITECH PROJECT, 2023
** my
** File description:
** Task02
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H

void call_flag(const char *format, int b, va_list list);
void call_flag2(const char *format, int b, va_list list);
int my_printf(const char *format, ...);
static long put_nbr_my(unsigned long nb);
static int str_int(int a);
void octal(unsigned int i);
void hexa_capital(unsigned int i);
void hexa_tiny(unsigned int i);
void u_unsigned(long n);
long my_put_nbr(long nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void float_dis(double n);
void secondaire(double temp1);
void scientific_notation_tiny(double n);
void tiny(int count);
void scientific_notation_capital(double n);
void capital(int count);
int my_printf(const char *format, ...);
void my_ls_a(const char *p);
void my_ls(const char *p);
void my_ls_l(const char *p);
void my_ls_d(const char *p);

#endif /* MY_H */

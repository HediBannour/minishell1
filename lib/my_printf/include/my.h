/*
** EPITECH PROJECT, 2023
** my
** File description:
** Task02
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H

typedef struct word_array_s {
    int a;
    int b;
    char **array;
}word_array_t;

typedef struct count_word_s {
    int count;
    int k;
    int *size_array_of_str;
}count_word_t;

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
int my_strlen(char *str);
void float_dis(double n);
void secondaire(double temp1);
void scientific_notation_tiny(double n);
void tiny(int count);
void scientific_notation_capital(double n);
void capital(int count);
int my_printf(const char *format, ...);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *src);

#endif /* MY_H */

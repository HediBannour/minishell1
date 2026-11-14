/*
** EPITECH PROJECT, 2023
** base_conversion
** File description:
** u o x X convertion and print in other base unsigned
*/

#include "./include/my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

static long put_nbr_my(unsigned long nb)
{
    int d = 1;
    long nbl = nb;

    while (nbl / d >= 10) {
        d = d * 10;
    }
    while (d >= 1) {
        my_putchar((nbl / d) % 10 + 48);
            d = d / 10;
    }
}

static int str_int(int a)
{
    int i = 0;

    if (a == 0) {
        i = 1;
    } else {
        while (a > 0){
            a = a / 10;
            i++;
        }
    }
    return i;
}

void octal(unsigned int i)
{
    char *p;
    int r = 0;
    int d = i;
    int size;
    int index = 0;

    size = str_int(i);
    p = malloc(sizeof(char) * size);
    for (int n = 0; n < size; n++) {
        d = i / 8;
        r = i % 8;
        i = i / 8;
        p[n] = r;
    }
    for (int index = size - 1; index >= 0; index--) {
        my_put_nbr(p[index]);
    }
}

void hexa_capital(unsigned int i)
{
    int t = i;
    int r = 1;
    int rest = i;
    int d = 0;

    for (int index = 0; r < i; i++) {
        r = r * 16;
    }
    for (int i = 0; r >= 16; i++){
        r = r / 16;
        d = rest / r;
        rest = rest % r;
        if (d > 9) {
            my_putchar(d + 55);
        } else {
            my_put_nbr(d);
        }
    }
}

void hexa_tiny(unsigned int i)
{
    int t = i;
    int r = 1;
    int rest = i;
    int d = 0;

    for (int index = 0; r < i; i++) {
        r = r * 16;
    }
    for (int i = 0; r >= 16; i++) {
        r = r / 16;
        d = rest / r;
        rest = rest % r;
        if (d > 9) {
            my_putchar(d + 87);
        } else {
            my_put_nbr(d);
        }
    }
}

void u_unsigned(long n)
{
    if (n < 0) {
        n = 4294967296 + n;
    }
    put_nbr_my(n);
}

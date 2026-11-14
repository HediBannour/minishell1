/*
** EPITECH PROJECT, 2023
** scientific notation
** File description:
** display a float in a scientific notation
*/

#include "./include/my.h"
#include <stdio.h>
#include <stdarg.h>

void scientific_notation_tiny(double n)
{
    int count = 0;
    int temp = 0;

    if (n == 0.0){
        my_putstr("0.000000e+00");
        return;
    }
    while ((n >= 10) || (n <= -10)){
        n = n / 10;
        count++;
    }
    if (n < 1 && n > -1){
        while ((n < 1) && (n > -1)){
            n = n * 10;
            count = count - 1;
        }
    }
    float_dis(n);
    tiny(count);
}

void tiny(int count)
{
    int temp = 0;

    my_putchar('e');
    if (count >= 0) {
        my_putchar('+');
        temp = count;
    }
    if (count < 0) {
        my_putchar('-');
        temp = count * (-1);
    }
    if (count < 10 && count > -10) {
        my_put_nbr(0);
    }
    my_put_nbr(temp);
}

void scientific_notation_capital(double n)
{
    int count = 0;
    int temp = 0;

    if (n == 0.0){
        my_putstr("0.000000E+00");
        return;
    }
    while ((n >= 10) || (n <= -10)) {
        n = n / 10;
        count++;
    }
    if (n < 1 && n > -1) {
        while ((n < 1) && (n > -1)) {
            n = n * 10;
            count = count - 1;
        }
    }
    float_dis(n);
    capital(count);
}

void capital(int count)
{
    int temp = 0;

    my_putchar('E');
    if (count >= 0){
        my_putchar('+');
        temp = count;
    }
    if (count < 0) {
        my_putchar('-');
            temp = count * (-1);
    }
    if (count < 10 && count > -10) {
        my_put_nbr(0);
    }
    my_put_nbr(temp);
}

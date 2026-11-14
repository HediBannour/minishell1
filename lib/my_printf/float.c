/*
** EPITECH PROJECT, 2023
** float
** File description:
** display a float
*/

#include "./include/my.h"
#include <stdio.h>
#include <stdarg.h>

void float_dis(double n)
{
    double t = 0;
    int power1 = 0;
    int temp = (int) n;
    double temp1 = n;

    if (n < 0) {
        my_putchar('-');
        temp = -1 * temp;
        temp1 = -1 * temp1;
    }
    power1 = 10000000;
    my_put_nbr(temp);
    my_putchar('.');
    temp1 = temp1 * power1;
    t = (double)temp * power1;
    temp1 = temp1 - t;
    secondaire(temp1);
}

void secondaire(double temp1)
{
    if ((int)temp1 % 10 >= 5){
        temp1 = temp1 + 10;
    }
    if ((int)temp1 == 0){
        my_putstr("000000");
    } else {
        my_put_nbr((int)temp1 / 10);
    }
}

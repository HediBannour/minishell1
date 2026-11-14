/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** task07
*/

#include "./include/my.h"

long my_put_nbr(long nb)
{
    long divider;
    long nbr = nb;

    if (nbr > 2147483647 || nbr < -2147483647)
        return 0;
    divider = 1;
    if (nbr < 0){
    my_putchar('-');
    nbr = nbr * -1;
    }
    while ((nbr / divider) >= 10){
        divider = divider * 10;
    }
    while (divider > 0){
        my_putchar((nbr / divider) % 10 + 48);
        divider = divider / 10;
    }
}

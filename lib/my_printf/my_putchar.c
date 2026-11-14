/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** t1
*/

#include "./include/my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

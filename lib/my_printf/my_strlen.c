/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** t1
*/

#include "./include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

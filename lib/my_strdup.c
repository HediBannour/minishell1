/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** test
*/

#include <stdlib.h>
#include "./my_printf/include/my.h"

char *my_strdup(char *src)
{
    char *str;
    int t = my_strlen(src);
    int i = 0;

    str = malloc(sizeof(char) * (t + 1));
    while (i < t){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

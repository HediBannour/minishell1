/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** t1
*/

#include <stdlib.h>
#include "./include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int size = 0;
    char *res;
    int k = 0;
    int l = 0;

    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++);
    size = i + j + 1;
    res = malloc(sizeof(char) * size);
    for (k = 0; dest[k] != '\0'; k++)
        res[k] = dest[k];
    for (l = 0; src[l] != '\0'; l++) {
        res[k] = src[l];
        k++;
    }
    res[k] = '\0';
    return res;
}

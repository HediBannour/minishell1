/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Si return 0 -> identique sinon
*/

#include "./my_printf/include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int count = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            count++;
    }
    if (count == 0)
        return 0;
    else
        return 1;
}

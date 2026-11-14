/*
** EPITECH PROJECT, 2024
** env.c
** File description:
** env.c
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../lib/my_printf/include/my.h"

void my_env(char *str, char **env, char **array)
{
    if (my_strcmp("env", str) == 0) {
        for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);
    } else if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v'
    && my_strlen(str) > 3)
        my_printf("env: '%s': No such file or directory\n", array[1]);
}

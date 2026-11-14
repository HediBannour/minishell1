/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../lib/my_printf/include/my.h"
#include "../include/my_minishell1.h"

int recup_nbr_line_from_env_for_unset(char **env, char *str)
{
    int a = 0;
    int i = 0;

    str = my_strcpy(str, "=");
    for (i = 0; env[i] != NULL; i++) {
        for (int j = 0; j < my_strlen(str); j++) {
            a = (env[i][j] != str[j]) ? 1 : a;
        }
        if (a == 0)
            return i;
        a = 0;
    }
    return -1;
}

char **unset_bis(char **env, int line_remo)
{
    int i = 0;
    int j = 0;

    for (i = line_remo; env[i + 1] != NULL; i++) {
        env[i] = malloc(sizeof(char) * (my_strlen(env[i + 1]) + 1));
        for (j = 0; j < my_strlen(env[i + 1]); j++)
            env[i][j] = env[i + 1][j];
        env[i][j] = '\0';
    }
    env[i] = NULL;
    return env;
}

char **unset(char **env, char **array)
{
    int count = 0;
    int line_remo = 0;
    int k = 0;

    if (my_strcmp(array[0], "unsetenv") != 0 || count > 2 || line_remo == -1)
        return env;
    for (count = 0; array[count] != NULL; count++);
    if (count == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return env;
    }
    line_remo = recup_nbr_line_from_env_for_unset(env, array[1]);
    return unset_bis(env, line_remo);
}

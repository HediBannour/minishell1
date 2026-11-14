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

static int count_char_until_separato(char *str, char sep)
{
    int i = 0;

    while (str[i] != sep) {
        i++;
    }
    return i;
}

static char **recup_env_args(char **env)
{
    char **env_args;
    int size_env_args = 0;
    int size_one_arg = 0;

    for (size_env_args = 0; env[size_env_args] != NULL; size_env_args++);
    env_args = malloc(sizeof(char *) * (size_env_args + 1));
    for (int i = 0; env[i] != NULL; i++) {
        size_one_arg = count_char_until_separato(env[i], '=');
        env_args[i] = malloc(sizeof(char) * (size_one_arg + 1));
        for (int j = 0; j < size_one_arg; j++) {
            env_args[i][j] = env[i][j];
        }
        env_args[i][size_one_arg] = '\0';
    }
    env_args[size_env_args] = NULL;
    return env_args;
}

int check_if_input_true(char *str, char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strcmp(str, array[i]) == 0)
            return 0;
    }
    return 1;
}

char **change_env(char **env, char **array, char **env_arg)
{
    for (int i = 0; env_arg[i] != NULL; i++) {
        if (my_strcmp(array[1], env_arg[i]) == 0) {
            env[i] = my_strcpy(my_strcpy(env_arg[i], "="), array[2]);
        }
    }
    return env;
}

char **add_to_env(char **env, char **array, char **env_arg, int nbr_input)
{
    int i = 0;
    int j = 0;
    char *line;

    for (i = 0; env[i] != NULL; i++);
    if (nbr_input == 3)
        line = my_strcpy(my_strcpy(array[1], "="), array[2]);
    if (nbr_input == 2)
        line = my_strcpy(array[1], "=");
    env[i] = malloc(sizeof(char) * (my_strlen(line) + 1));
    env[i + 1] = malloc(sizeof(NULL));
    for (j = 0; line[j] != '\0'; j++) {
        env[i][j] = line[j];
    }
    env[i][j] = '\0';
    env[i + 1] = NULL;
    return env;
}

char **my_setenv(char **env, char *str, char **array)
{
    char **env_arg;
    int nbr_input = count_word(str, ' ');

    if (nbr_input > 4 || my_strcmp(array[0], "setenv") != 0)
        return env;
    if (nbr_input == 1) {
        my_env("env", env, array);
        return env;
    }
    env_arg = recup_env_args(env);
    if (nbr_input == 2 || nbr_input == 3)
        return add_to_env(env, array, env_arg, nbr_input);
    if (check_if_input_true(array[1], env_arg) == 0)
        if (my_strcmp(array[3], "1") == 0)
            return change_env(env, array, env_arg);
        else if (my_strcmp(array[3], "0") == 0)
            return env;
    if (check_if_input_true(array[1], env_arg) == 1)
        return add_to_env(env, array, env_arg, nbr_input);
    return env;
}


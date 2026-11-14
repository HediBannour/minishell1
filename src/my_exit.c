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

void my_exit(char *str)
{
    if (my_strcmp(str, "exit") == 0) {
        my_printf("exit\n");
        exit(EXIT_SUCCESS);
    }
}

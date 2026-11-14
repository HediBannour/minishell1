/*
** EPITECH PROJECT, 2024
** my_pwd.c
** File description:
** pwd
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

void my_pwd(char *str)
{
    char buffer[1024];

    if (my_strcmp(str, "pwd") != 0)
        return;
    if (getcwd(buffer, 1024) == NULL) {
        my_printf("Get current working directory\n");
        return;
    } else
        my_printf("%s\n", buffer);
}

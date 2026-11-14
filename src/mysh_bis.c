/*
** EPITECH PROJECT, 2024
** mysh_bis.c
** File description:
** mysh_bis.c
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/my_minishell1.h"
#include "../lib/my_printf/include/my.h"

char *file_path(char **env)
{
    int line_of_path = recup_nbr_line_from_env(env, "PATH=");
    char *path = malloc(sizeof(char) * (my_strlen(env[line_of_path]) - 4));
    int i = 0;

    for (i = 0; env[line_of_path][i + 5] != '\0'; i++) {
        path[i] = env[line_of_path][i + 5];
    }
    path[i] = '\0';
    return path;
}

char *file_oldpwd(char **env)
{
    int line_of_oldpwd = recup_nbr_line_from_env(env, "OLDPWD=");
    char *oldpwd = malloc(sizeof(char) * (my_strlen(env[line_of_oldpwd]) - 6));
    int i = 0;

    for (i = 0; env[line_of_oldpwd][i + 7] != '\0'; i++) {
        oldpwd[i] = env[line_of_oldpwd][i + 7];
    }
    oldpwd[i] = '\0';
    return oldpwd;
}

char *file_pwd(char **env)
{
    int line_of_pwd = recup_nbr_line_from_env(env, "PWD=");
    char *pwd = malloc(sizeof(char) * (my_strlen(env[line_of_pwd]) - 3));
    int i = 0;

    for (i = 0; env[line_of_pwd][i + 4] != '\0'; i++) {
        pwd[i] = env[line_of_pwd][i + 4];
    }
    pwd[i] = '\0';
    return pwd;
}

char *file_home(char **env)
{
    int line_of_home = recup_nbr_line_from_env(env, "HOME=");
    char *home = malloc(sizeof(char) * (my_strlen(env[line_of_home]) - 4));
    int i = 0;

    for (i = 0; env[line_of_home][i + 5] != '\0'; i++) {
        home[i] = env[line_of_home][i + 5];
    }
    home[i] = '\0';
    return home;
}

old_and_pwd_t *file_the_struct(char **env)
{
    old_and_pwd_t *shell = malloc(sizeof(old_and_pwd_t));
    int line_of_oldpwd = recup_nbr_line_from_env(env, "OLDPWD=");
    int line_of_home = recup_nbr_line_from_env(env, "HOME=");
    int line_of_pwd = recup_nbr_line_from_env(env, "PWD=");
    int line_of_path = recup_nbr_line_from_env(env, "PATH=");

    if (line_of_oldpwd != 1)
        shell->oldpwd = file_oldpwd(env);
    if (line_of_pwd != 1)
        shell->pwd = file_pwd(env);
    if (line_of_home != 1)
        shell->home = file_home(env);
    if (line_of_path != 1)
        shell->path = file_path(env);
    shell->env = copy_array_from_array(env);
    return shell;
}

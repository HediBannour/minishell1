/*
** EPITECH PROJECT, 2024
** my_cd.h
** File description:
** my_cd
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

int recup_nbr_line_from_env(char **env, char *str)
{
    int a = 0;
    int size_return = my_strlen(str);
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        for (int j = 0; j < size_return; j++) {
            a = (env[i][j] != str[j]) ? 1 : a;
        }
        if (a == 0)
            return i;
        a = 0;
    }
    return -1;
}

static int go_to_home(old_and_pwd_t *shell)
{
    if (chdir(shell->home) == -1)
        return -1;
    return 0;
}

static old_and_pwd_t *change_home_env(old_and_pwd_t *shell)
{
    int line_of_oldpwd = recup_nbr_line_from_env(shell->env, "OLDPWD");
    int line_of_pwd = recup_nbr_line_from_env(shell->env, "PWD");

    shell->oldpwd = my_strdup(shell->pwd);
    shell->pwd = my_strdup(shell->home);
    if (line_of_oldpwd != -1)
        shell->env[line_of_oldpwd] = my_strcpy("OLDPWD=", shell->oldpwd);
    if (line_of_pwd != -1)
        shell->env[line_of_pwd] = my_strcpy("PWD=", shell->pwd);
    return shell;
}

old_and_pwd_t *change_env_from_link(old_and_pwd_t *shell)
{
    char pwd[1024];
    int line_of_oldpwd = recup_nbr_line_from_env(shell->env, "OLDPWD");
    int line_of_pwd = recup_nbr_line_from_env(shell->env, "PWD");

    if (getcwd(pwd, 1024) == NULL)
        return shell;
    shell->oldpwd = my_strdup(shell->pwd);
    shell->pwd = my_strdup(pwd);
    if (line_of_oldpwd != -1)
        shell->env[line_of_oldpwd] = my_strcpy("OLDPWD=", shell->oldpwd);
    if (line_of_pwd != -1)
        shell->env[line_of_pwd] = my_strcpy("PWD=", shell->pwd);
    return shell;
}

old_and_pwd_t *my_cd_go_to_pre(old_and_pwd_t *shell, int count)
{
    char pwd[1024];
    int i = 0;

    if (count == 0) {
        my_printf(": No such file or directory.\n");
        return shell;
    }
    if (getcwd(pwd, 1024) == NULL)
        return shell;
    if (chdir(shell->oldpwd) == -1) {
        my_printf("Don't found previous directory.\n");
        return shell;
    }
    return change_env_from_link(shell);
}

static old_and_pwd_t *check_if_dir(char **array, old_and_pwd_t *shell)
{
    if (access(array[1], X_OK) == 0) {
            my_printf("%s: Not a directory.\n", array[1]);
            return shell;
        } else {
            my_printf("%s: No such file or directory.\n", array[1]);
            return shell;
        }
    return shell;
}

old_and_pwd_t *my_cd_bis(char **array, old_and_pwd_t *shell)
{
    static int count = 0;

    if (array[1] == NULL || my_strcmp(array[1], "~") == 0)
        if (go_to_home(shell) == -1) {
            my_printf("Change current directory failed.\n");
            return shell;
        } else {
            count++;
            return change_home_env(shell);
        }
    if (my_strcmp(array[1], "-") == 0)
        return my_cd_go_to_pre(shell, count);
    if (chdir(array[1]) == -1) {
        return check_if_dir(array, shell);
    } else {
        count++;
        return change_env_from_link(shell);
    }
    return shell;
}

old_and_pwd_t *my_cd(char **array, old_and_pwd_t *shell)
{
    int line_of_oldpwd = recup_nbr_line_from_env(shell->env, "OLDPWD");
    int line_of_pwd = recup_nbr_line_from_env(shell->env, "PWD");
    int a = 0;

    for (a = 0; array[a] != NULL; a++);
    if (a > 2) {
        my_printf("cd: Too many arguments.\n");
        return shell;
    }
    if (my_strcmp(array[0], "cd") != 0)
        return shell;
    return my_cd_bis(array, shell);
}

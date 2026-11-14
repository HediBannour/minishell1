/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "../lib/my_printf/include/my.h"
#include "../include/my_minishell1.h"

static int check_if_its_a_link(char **array, char **env, char *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            a = 0;
    if (a != 0)
        return 1;
    if (access(array[0], X_OK) != 0) {
        my_printf("%s: Command not found.\n", str);
        return 1;
    } else if (access(array[0], R_OK) != 0 || access(array[0], W_OK) != 0) {
        my_printf("%s:  Permission denied.\n", str);
        return 1;
    }
    if (a == 0 && fork() == 0) {
        if (execve(str, array, env) == -1)
            return 84;
    } else
        wait(NULL);
    return 0;
}

static int check_path(char **env)
{
    int nbr_line = recup_nbr_line_from_env(env, "PATH=");

    if (nbr_line == -1) {
        return -1;
    }
    return 0;
}

char **copy_array_from_array(char **tab1)
{
    char **array;
    int i;
    int k = 0;

    for (i = 0; tab1[i] != NULL; i++);
    array = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; tab1[j] != NULL; j++) {
        array[j] = malloc(sizeof(char) * (my_strlen(tab1[j]) + 1));
        for (k = 0; tab1[j][k] != '\0'; k++) {
            array[j][k] = tab1[j][k];
        }
        array[j][my_strlen(tab1[j])] = '\0';
    }
    array[i] = NULL;
    return array;
}

char **recup_path_fonction(char **env, old_and_pwd_t *shell)
{
    char **res;

    shell->path = valide_string(shell->path);
    res = str_word_array(shell->path, ':');
    return res;
}

static int check_and_print_status(char **array, char *path)
{
    char *to_access = my_strcpy(path, array[0]);
    int a = access(to_access, X_OK);

    if (a == 0)
        return 0;
    return 84;
}

static int check_if_bis(char **array, char **env, char *path)
{
    int child = fork();
    int tmp;

    path = my_strcpy(path, "//");
    if (check_and_print_status(array, path) == 0 && child == 0) {
        if (execve(my_strcpy(path, array[0]), array, env) == -1) {
            my_printf("%s: Permission denied.\n");
            return 84;
        }
    } else {
        waitpid(child, &tmp, 0);
        if (WIFSIGNALED(tmp) && WTERMSIG(tmp) == SIGSEGV) {
            my_printf("Segmentation fault\n");
            return 139;
        }
    }
    if (access(my_strcpy(path, array[0]), X_OK) == 0)
        return 0;
    return -1;
}

static int cod(char **array, old_and_pwd_t *shell, char **path)
{
    for (int i = 0; path[i] != NULL; i++)
        if (check_if_bis(array, shell->env, path[i]) == 0)
            return 0;
    return 1;
}

int check_if_it_true_input(char **t, old_and_pwd_t *s, char *str)
{
    if (my_strlen(str) <= 1)
        return 84;
    if (my_strcmp(t[0], "cd") == 0 || my_strcmp(t[0], "setenv") == 0 ||
    my_strcmp(t[0], "unsetenv") == 0 || my_strcmp(t[0], "env") == 0 ||
    my_strcmp(t[0], "exit") == 0) {
        my_exit(str);
        my_env(str, s->env, t);
        s->env = my_setenv(s->env, str, t);
        s->env = unset(s->env, t);
        s = (my_strcmp(t[0], "cd") == 0) ? my_cd(t, s) : s;
    } else {
        if (check_if_its_a_link(t, s->env, str) == 0)
            return 0;
        if (s->path_exe != NULL && cod(t, s, s->path_exe) == 0)
            return 0;
        if (check_if_slach(str) != 0)
            my_printf("%s: Command not found.\n", str);
    }
    return 0;
}

int begin(char **env)
{
    size_t size_input;
    size_t size_str = 32;
    char *str;
    old_and_pwd_t *shell = file_the_struct(env);

    str = malloc(sizeof(char) * size_str);
    shell->path_exe = NULL;
    if (check_path(env) == 0)
        shell->path_exe = recup_path_fonction(env, shell);
    while (1) {
        if (isatty(0))
            my_printf("$> ");
        size_input = getline(&str, &size_str, stdin);
        if (size_input == -1)
            return -1;
        str = valide_string(str);
        check_if_it_true_input(str_word_array(str, ' '), shell, str);
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1) {
        my_printf("No need argument.\n");
        return 84;
    }
    begin(env);
    return 0;
}

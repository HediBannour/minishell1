/*
** EPITECH PROJECT, 2024
** lib.h
** File description:
** lib.h
*/

#ifndef MY_MINISHELL1_H
    #define MY_MINISHELL1_H

typedef struct old_and_pwd_s {
    char *oldpwd;
    char *pwd;
    char *home;
    char *path;
    char **env;
    char **path_exe;
} old_and_pwd_t;

int check_if_slach(char *str);
void my_exit(char *str);
old_and_pwd_t *my_cd(char **array, old_and_pwd_t *shell);
void my_env(char *str, char **env, char **array);
char **my_setenv(char **env, char *str, char **array);
void my_pwd(char *str);
int count_word(char *str, char separateur);
char *replace_n_by_0(char *str);
char **str_word_array(char *str, char separateur);
char *valide_string(char *str);
char **unset(char **env, char **array);
char **copy_array_from_array(char **tab1);
int recup_nbr_line_from_env(char **env, char *str);
char *my_strdup(char *src);
old_and_pwd_t *file_the_struct(char **env);
#endif /* MY_MINISHELL1_H */

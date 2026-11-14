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
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "./my_printf/include/my.h"

int check_if_slach(char *str)
{
    int a = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            a = 0;
    return a;
}

char *valide_string(char *str)
{
    int begin = 0;
    int sen = 0;
    int stop_copy = 0;
    char *clean_str;
    int i = 0;
    int count = 0;

    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == '\t')
            str[j] = ' ';
    for (sen = 0; str[sen] != '\n' && str[sen] != '\0'; sen++);
    for (begin = 0; str[begin] != '\n' && str[begin] == ' '; begin++);
    for (int j = sen - 1; j >= begin && str[j] == ' '; j--)
        if (str[j] == ' ')
            stop_copy++;
    clean_str = malloc(sizeof(char) * ((sen - begin - stop_copy) + 1));
    for (i = 0; i < (sen - begin - stop_copy); i++)
        clean_str[i] = str[i + begin];
    clean_str[i] = '\0';
    return clean_str;
}

int count_word(char *str, char separateur)
{
    int nbr_of_word = 0;
    int new_world = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separateur && str[i + 1] != separateur)
            new_world = 1;
        if (str[i] != separateur && new_world == 1) {
            nbr_of_word++;
            new_world = 0;
        }
    }
    return nbr_of_word + 1;
}

static count_word_t *count_byte_bis(char *str, char s, count_word_t *st, int i)
{
        if (str[i] != s) {
            st->count++;
        }
        if (str[i] == s) {
            if (st->count > 0) {
                st->size_array_of_str[st->k] = st->count;
                st->k++;
                st->count = 0;
            }
        }
    return st;
}

static int *count_nbr_of_byte(char *str, char separateur)
{
    int nbr_of_word = count_word(str, separateur);
    count_word_t *st = malloc(sizeof(count_word_t));

    st->size_array_of_str = malloc(sizeof(int) * (nbr_of_word + 1));
    st->count = 0;
    st->k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        st = count_byte_bis(str, separateur, st, i);
        if (i == my_strlen(str))
            return st->size_array_of_str;
    }
    if (st->count > 0) {
        st->size_array_of_str[st->k] = st->count;
        st->count = 0;
    }
    st->size_array_of_str[nbr_of_word] = 0;
    return st->size_array_of_str;
}

word_array_t *str_word_array_bis(char *str, char sep, int i, word_array_t *st)
{
    for (int j = 0; j < st->b; j++) {
        while (str[st->a] == sep) {
            st->a++;
        }
        if (str[st->a] != sep) {
            st->array[i][j] = str[st->a];
            st->a++;
        }
    }
    st->array[i][st->b] = '\0';
    return st;
}

char **str_word_array(char *str, char separateur)
{
    int nbr_word = count_word(str, separateur);
    int *tmp = count_nbr_of_byte(str, separateur);
    word_array_t *stru = malloc(sizeof(word_array_t));

    stru->a = 0;
    stru->array = malloc(sizeof(char *) * (nbr_word + 1));
    for (int i = 0; i < nbr_word; i++) {
        stru->b = tmp[i];
        stru->array[i] = malloc(sizeof(char) * (stru->b + 1));
        stru = str_word_array_bis(str, separateur, i, stru);
    }
    stru->array[nbr_word] = NULL;
    return stru->array;
}

/*
** EPITECH PROJECT, 2018
** make_table_int_redirect.c
** File description:
** make int table for redirect
*/

#include "my.h"
#include "minishell2.h"

int verify_redirect_formating(char *command)
{
	return (1);
}

void increment_int_table_redirect(char *command, int *redir, int *i, int *iter)
{
	if (command[*i] == '|') {
		redir[*iter] = 1;
		*iter += 1;
	} if (command[*i] == '<' && command[*i + 1] != '<') {
		redir[*iter] = 2;
		*iter += 1;
	} if (command[*i] == '<' && command[*i + 1] == '<') {
		redir[*iter] = 3;
		*iter += 1;
		*i += 1;
	} if (command[*i] == '>' && command[*i + 1] != '>') {
		redir[*iter] = 4;
		*iter += 1;
	} if (command[*i] == '>' && command[*i + 1] == '>') {
		redir[*iter] = 5;
		*iter += 1;
		*i += 1;
	}
}

int *make_table_int_redirect(char *command)
{
	int iter = 0;
	int *arr_redirect = malloc(sizeof(int) * (count_redirect(command) + 1));

	for (int i = 0; command[i] != '\0'; i++) {
		increment_int_table_redirect(command, arr_redirect, &i, &iter);
	}
	arr_redirect[iter] = -1;
	return (arr_redirect);
}

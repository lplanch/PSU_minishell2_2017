/*
** EPITECH PROJECT, 2018
** make_table_int_redirect.c
** File description:
** make int table for redirect
*/

#include "my.h"
#include "minishell2.h"

int char_is_redir(char chr)
{
	if (chr == '|' || chr == '<' || chr == '>')
		return (1);
	return (0);
}

int verify_redirect_formating(char *cmd)
{
	int found = 0;
	int len = my_strlen(cmd);

	if (char_is_redir(cmd[0]) || char_is_redir(cmd[len - 1])) {
		my_putstrror("Invalid null command.\n");
		return (0);
	}
	for (int i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] != '|' && cmd[i] != ' ')
			found = 1;
		if (cmd[i] == '|' && found == 1) {
			found = 0;
		} else if (cmd[i] == '|' && found == 0) {
			my_putstrror("Invalid null command.\n");
			return (0);
		} if (i < len - 3 && (cmd[i] == '<' || cmd[i] == '>') &&
		(cmd[i + 1] == '<' || cmd[i + 1] == '>') &&
		(cmd[i + 2] == '>' || cmd[i + 2] == '>')) {
			my_putstrror("Missing name for redirect.\n");
			return (0);
		}
	}
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

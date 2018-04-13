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
	if (chr == '|')
		return (1);
	if (chr == '<')
		return (2);
	if (chr == '>')
		return (3);
	return (0);
}

int iter_redirect_verify(char *cmd, int i, int **iters)
{
	if (cmd[i] != ' ' && char_is_redir(cmd[i]) == 0)
		*iters[0] = 0;
	if (char_is_redir(cmd[i]) > 0 && *iters[0] == 0) {
		*iters[0] = char_is_redir(cmd[i]);
	} else if (char_is_redir(cmd[i]) && *iters[0] == 1) {
		my_putstrror("Invalid null command.\n");
		return (0);
	} if ((char_is_redir(cmd[i]) == 2 && *iters[0] == 3) ||
	(char_is_redir(cmd[i]) == 3 && *iters[0] == 2) || (*iters[2] == 1 &&
	char_is_redir(cmd[i]) > 1 && char_is_redir(cmd[i]) == *iters[0])) {
		my_putstrror("Missing name for redirect.\n");
		return (0);
	}
	if (*iters[1] == 0 && char_is_redir(cmd[i]) > 1 &&
	char_is_redir(cmd[i]) == *iters[0]) {
		*iters[2] = 1;
	} else
		*iters[2] = 0;
	*iters[1] = (cmd[i] == ' ' ? 1 : 0);
	return (1);
}

int verify_redirect_formating(char *cmd)
{
	int found = (cmd[0] != '\0' ? 1 : 0);
	int space = 0;
	int dobble = 0;
	int len = my_strlen(cmd);

	for (int i = 0; cmd[i] != '\0'; i++) {
		if (!iter_redirect_verify(cmd, i,
		(int*[3]){&found, &space, &dobble}))
			return (0);
	}
	if (found == 1) {
		my_putstrror("Invalid null command.\n");
		return (0);
	} else if (found > 1) {
		my_putstrror("Missing name for redirect.\n");
		return (0);
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

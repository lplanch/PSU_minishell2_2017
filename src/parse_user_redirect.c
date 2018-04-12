/*
** EPITECH PROJECT, 2018
** parse_user_redirect.c
** File description:
** file to stock all functions about parsing user redirections
*/

#include "my.h"
#include "minishell2.h"

int count_redirect(char *command)
{
	int result = 0;

	for (int i = 0; command[i] != '\0'; i++) {
		if (command[i] == '|')
			result += 1;
		if (command[i] == '<' && command[i + 1] != '<')
			result += 1;
		if (command[i] == '<' && command[i + 1] == '<') {
			result += 1;
			i += 1;
		} if (command[i] == '>' && command[i + 1] != '>')
			result += 1;
		if (command[i] == '>' && command[i + 1] == '>') {
			result += 1;
			i += 1;
		}
	}
	return (result);
}

char **malloc_array_redirect(char *cmd)
{
	char **result = malloc(sizeof(char *) * (count_redirect(cmd) + 2));
	int iter = 0;
	int count = 0;

	for (int i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] == '|' || (cmd[i] == '<' && cmd[i + 1] != '<') ||
		(cmd[i] == '>' && cmd[i + 1] != '>')) {
			result[count] = my_calloc(sizeof(char) * (iter + 1));
			count += 1;
			iter = 0;
		} else if ((cmd[i] == '>' && cmd[i + 1] == '>') ||
		(cmd[i] == '<' && cmd[i + 1] == '<')) {
			result[count] = my_calloc(sizeof(char) * (iter + 1));
			count += 1;
			i += 1;
			iter = 0;
		} else
			iter += 1;
	}
	result[count] = my_calloc(sizeof(char) * (iter + 1));
	return (result);
}

char **make_result_clean_redir(char **result, int count)
{
	char *temp;

	result[count + 1] = NULL;
	for (int i = 0; result[i] != NULL; i++) {
		temp = result[i];
		result[i] = make_clean_cmd(result[i]);
		free(temp);
	}
	return (result);
}

char **make_table_redir_command(char *cmd)
{
	char **result = malloc_array_redirect(cmd);
	int count = 0;
	int iter = 0;

	for (int i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] == '|' || (cmd[i] == '<' && cmd[i + 1] != '<') ||
		(cmd[i] == '>' && cmd[i + 1] != '>')) {
			count += 1;
			iter = 0;
		} else if ((cmd[i] == '>' && cmd[i + 1] == '>') ||
		(cmd[i] == '<' && cmd[i + 1] == '<')) {
			count += 1;
			i += 1;
			iter = 0;
		} else {
			result[count][iter] = cmd[i];
			iter += 1;
		}
	}
	return (make_result_clean_redir(result, count));
}

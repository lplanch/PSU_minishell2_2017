/*
** EPITECH PROJECT, 2018
** cd_handling.c
** File description:
** cd main file to stock all functions about it
*/

#include "my.h"
#include "minishell2.h"

int count_command_args(char *cmd)
{
	int is_inside = 0;
	int turn = 0;
	int spaces = 0;

	for (int i = 0; cmd[i] != '\0'; i++) {
		turn = 0;
		if (is_inside == 0 && (cmd[i] == '\'' || cmd[i] == '\"')) {
			is_inside = (cmd[i] == '\'' ? 1 : 2);
			turn = 1;
		} if (turn == 0 && is_inside == 1 && cmd[i] == '\'')
			is_inside = 0;
		if (turn == 0 && is_inside == 2 && cmd[i] == '\"')
			is_inside = 0;
		if (cmd[i] == ' ' && cmd[i - 1] != '\\' && is_inside == 0)
			spaces += 1;
	}
	return (spaces);
}

char *make_pathname(char *pathname)
{
	int iter = 0;
	char *result = my_calloc(sizeof(char) * (my_strlen(pathname) + 1));

	if (pathname[0] == '\'' || pathname[0] == '\"') {
		for (int i = 1; i < my_strlen(pathname) - 1; i++)
			result[i - 1] = pathname[i];
		return (result);
	}
	for (int i = 0; pathname[i] != '\0'; i++) {
		if (pathname[i] == '\\' && pathname[i + 1] == ' ')
			i += 1;
		result[iter] = pathname[i];
		iter += 1;
	}
	return (result);
}

void main_cd_command(svar_t *svar, char *command)
{
	char *temp = get_args(command);
	char *pathname;
	int iter = 0;
	int (*right_cd[4])(svar_t *svar, char *command, char *pathname) =
	{cd_jalapeno, cd_less, cd_pathname, NULL};

	if (temp != NULL) {
		pathname = make_pathname(temp);
		free(temp);
	} else
		pathname = temp;
	if (count_command_args(command) > 1) {
		my_putstrror("cd: Too many arguments.\n");
		svar->returnv = 1;
		return;
	}
	for (int i = 0; right_cd[i] != NULL && iter == 0; i++) {
		iter = right_cd[i](svar, command, pathname);
	}
	free(pathname);
}

int verify_cd_command(svar_t *svar, char *command)
{
	if (!verify_command(command, "cd"))
		return (0);
	svar->returnv = 0;
	main_cd_command(svar, command);
	return (1);
}

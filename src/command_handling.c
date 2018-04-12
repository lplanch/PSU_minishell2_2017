/*
** EPITECH PROJECT, 2018
** command_handling.c
** File description:
** play with all args and commands to have a better life
*/

#include "my.h"
#include "minishell2.h"

void loop_semicolon(char *command, char *result, int *iter, int i)
{
	if (command[i] == ';' && i != 0 && command[i - 1] != ' ') {
		result[*iter + i] = ' ';
		*iter += 1;
	} if (command[i] == ';' && command[i + 1] != ' ') {
		result[*iter + i] = command[i];
		result[*iter + i + 1] = ' ';
		*iter += 1;
	} else
		result[*iter + i] = command[i];
}

char *semicolon_formating(char *command)
{
	int nbr_to_add = 1;
	int iter = 0;
	char *result;

	for (int i = 0; command[i] != '\0'; i++) {
		if (command[i] == ';')
			nbr_to_add += 2;
	}
	result = my_calloc(sizeof(char) * (my_strlen(command) + nbr_to_add));
	for (int i = 0; command[i] != '\0'; i++) {
		loop_semicolon(command, result, &iter, i);
	}
	free(command);
	return (result);
}

char **malloc_table_command(char *cmd)
{
	char **result = malloc(sizeof(char *) * (count_chr(cmd, ';') + 2));
	int iter = 0;
	int count = 0;

	for (int i = (cmd[0] == ';' ? 1 : 0); cmd[i] != '\0'; i++) {
		if (cmd[i] == ';') {
			result[count] = my_calloc(sizeof(char) * (iter + 1));
			count += 1;
			iter = 0;
		} else
			iter += 1;
	}
	result[count] = my_calloc(sizeof(char) * (iter + 1));
	return (result);
}

char **make_table_command(char *cmd)
{
	char **result = malloc_table_command(cmd);
	int count = 0;
	int iter = 0;
	char *temp;

	for (int i = (cmd[0] == ';' ? 1 : 0); cmd[i] != '\0'; i++) {
		if (cmd[i] == ';' && cmd[i + 1] != ';' && cmd[i + 1] != '\0') {
			count += 1;
		} else
			result[count][iter] = cmd[i];
		iter = (cmd[i] == ';' ? 0 : iter + 1);
	}
	result[count + 1] = NULL;
	for (int i = 0; result[i] != NULL; i++) {
		temp = result[i];
		result[i] = make_clean_cmd(result[i]);
		free(temp);
	}
	return (result);
}

/*
** EPITECH PROJECT, 2018
** command_formating.c
** File description:
** file to stock all functions about formating
*/

#include "my.h"
#include "minishell2.h"

char *get_command_without_args(char *cmd)
{
	int len = 0;
	char *result;

	for (int i = 0; cmd[i] != '\0' &&
	cmd[i] != ' ' && cmd[i] != '\t'; i++) {
		len += 1;
	}
	result = (char *)my_calloc(sizeof(char) * (len + 1));
	for (int i = 0; cmd[i] != '\0' &&
	cmd[i] != ' ' && cmd[i] != '\t'; i++) {
		result[i] = cmd[i];
	}
	return(result);
}

int count_clean_cmd(char *buff)
{
	int count = 0;
	int len = 0;

	for (int i = 0; buff[i] != '\0'; i++) {
		if (buff[i] != '\t' && buff[i] != ' ') {
			count = 1;
			len += 1;
		} if (count == 1 && (buff[i] == '\t' || buff[i] == ' ')) {
			count = 0;
			len += 1;
		}
	}
	return(len);
}

char *make_clean_cmd(char *buff)
{
	int len = count_clean_cmd(buff);
	int count = 0;
	int j = 0;
	char *result = malloc(sizeof(char) * (len + 1));

	for (int i = 0; buff[i] != '\0'; i++) {
		if (buff[i] != '\t' && buff[i] != ' ') {
			count = 1;
			result[j] = buff[i];
			j += 1;
		} if (count == 1 && (buff[i] == '\t' || buff[i] == ' ')) {
			count = 0;
			result[j] = ' ';
			j += 1;
		}
	}
	if (j > 0)
		result[j - 1] = (result[j - 1] == ' ' ? '\0' : result[j - 1]);
	result[j] = '\0';
	return(result);
}

void get_user_command(svar_t *svar)
{
	svar->t_cmd = get_next_line(0);
	if (svar->t_cmd == NULL)
		return;
	svar->c_cmd = make_clean_cmd(svar->t_cmd);
	svar->n_cmd = get_command_without_args(svar->c_cmd);
}

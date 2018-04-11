/*
** EPITECH PROJECT, 2018
** verify_user_command.c
** File description:
** file to know how to use user command
*/

#include "my.h"
#include "minishell2.h"

void start_binary_command(svar_t *svar, char *command)
{
	char *command_name;
	int iter = 0;

	if (search_env("PATH", svar) == 1)
		iter = exec_outside(svar, command);
	if (!iter && command[0] != '\0') {
		command_name = get_command_without_args(command);
		my_putstrror(command_name);
		my_putstrror(": Command not found.\n");
		free(command_name);
		svar->returnv = 1;
	}
}

void verify_user_command(svar_t *svar, char *command)
{
	int iter = 0;
	int (*diff_cmd[9])(svar_t *svar, char *command) =
	{verify_exit_command, verify_cd_command, verify_env_command,
		verify_setenv_command, verify_unsetenv_command,
		verify_binary_command, exec_outside, NULL};

	if (svar->done != 0)
		return;
	for (int i = 0; diff_cmd[i] != NULL && iter == 0; i++)
		iter = (*diff_cmd[i])(svar, command);
	if (!iter) {
		start_binary_command(svar, command);
	}
}

void parse_user_commands(svar_t *svar)
{
	if (svar->done != 0)
		return;
	for (int i = 0; svar->c_cmd[i] != NULL; i++) {
		verify_user_command(svar, svar->c_cmd[i]);
	}
}

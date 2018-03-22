/*
** EPITECH PROJECT, 2018
** verify_user_command.c
** File description:
** file to know how to use user command
*/

#include "my.h"
#include "minishell2.h"

void verify_user_command(svar_t *svar)
{
	int iter = 0;
	int (*diff_cmd[4])(svar_t *svar) =
	{verify_exit_command, verify_env_command, verify_binary_command, NULL};

	if (svar->done != 0)
		return;
	for (int i = 0; diff_cmd[i] != NULL && iter == 0; i++)
		iter = (*diff_cmd[i])(svar);
	if (!iter) {
		if (search_env("PATH", svar) == 1)
			iter = exec_outside(svar);
		else
			iter = exec_outside_without_path(svar);
		if (!iter && svar->t_cmd[0] != '\0') {
			my_putstrror(svar->n_cmd);
			my_putstrror(": Command not found.\n");
		}
	}
}

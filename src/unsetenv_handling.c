/*
** EPITECH PROJECT, 2018
** unsetenv_handling.c
** File description:
** unsetenv file
*/

#include "my.h"
#include "minishell2.h"

void main_unsetenv(svar_t *svar, char *command)
{
	char *t_arg;
	int nbr_args = count_chr(command, ' ');

	if (nbr_args < 1) {
		my_putstrror("unsetenv: Too few arguments.\n");
		svar->returnv = 1;
		return;
	} for (int i = 0; i < nbr_args; i++) {
		t_arg = get_args_nbr(command, i + 1);
		svar->c_env = my_tbl_rm(svar->c_env, search_env(t_arg, svar));
		free(t_arg);
	}
}

int verify_unsetenv_command(svar_t *svar, char *command)
{
	if (!verify_command(command, "unsetenv"))
		return (0);
	svar->returnv = 0;
	main_unsetenv(svar, command);
	return (1);
}

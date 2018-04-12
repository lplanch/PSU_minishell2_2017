/*
** EPITECH PROJECT, 2018
** exit_handling.c
** File description:
** file for exit command handling
*/

#include "my.h"
#include "minishell2.h"

int verify_exit_command(svar_t *svar, char *command)
{
	char *temp = get_command_without_args(command);

	if (my_strcmp(temp, "exit") != 0)
		return (0);
	svar->done = 1;
	svar->returnv = 0;
}

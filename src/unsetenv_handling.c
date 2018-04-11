/*
** EPITECH PROJECT, 2018
** unsetenv_handling.c
** File description:
** unsetenv file
*/

#include "my.h"
#include "minishell2.h"

int verify_unsetenv_command(svar_t *svar, char *command)
{
	if (!verify_command(command, "unsetenv"))
		return (0);
	my_putstr("unsetenv\n");
	svar->returnv = 0;
	return (1);
}

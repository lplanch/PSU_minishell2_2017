/*
** EPITECH PROJECT, 2018
** exit_handling.c
** File description:
** file for exit command handling
*/

#include "my.h"
#include "minishell2.h"

int verify_exit_command(svar_t *svar)
{
	if (!verify_command(svar->t_cmd, "exit"))
		return (0);
	svar->done = 1;
}

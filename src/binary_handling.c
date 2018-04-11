/*
** EPITECH PROJECT, 2018
** binary_handling.c
** File description:
** file to stock all functions about executing a binary
*/

#include "my.h"
#include "minishell2.h"

int verify_binary_command(svar_t *svar, char *command)
{
	struct stat fstat;

	if (stat(command, &fstat) < 0)
		return (0);
	if (!S_ISDIR(fstat.st_mode) && fstat.st_mode & S_IXUSR) {
		exec_out_prm(command, command, svar);
		svar->returnv = 0;
	} else {
		my_putstrror(command);
		my_putstrror(": Permission denied.\n");
		svar->returnv = 1;
	}
	return (1);
}

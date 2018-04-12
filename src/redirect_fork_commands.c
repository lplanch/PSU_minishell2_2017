/*
** EPITECH PROJECT, 2018
** redirect_fork_commands.c
** File description:
** file to stock all functions about redirect and fork user commands
*/

#include "my.h"
#include "minishell2.h"

void pipe_command(svar_t *svar, char *command, int *arr_fd, int *iter)
{
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		if (iter[0] > 0)
			dup2(arr_fd[iter[0] * 2 - 2], 0);
		if (iter[0] < iter[1] - 1)
			dup2(arr_fd[iter[0] * 2 + 1], 1);
		for (int i = 0; i < iter[1] * 2 - 2; i += 2) {
			close(arr_fd[i]);
			close(arr_fd[i + 1]);
		}
		verify_user_command(svar, command);
		exit(svar->returnv);
	}
}

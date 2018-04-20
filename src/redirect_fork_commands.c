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
		for (int i = 0; i < iter[1] * 2 - 2; i++)
			close(arr_fd[i]);
		verify_user_command(svar, command);
		exit(svar->returnv);
	}
}

void right_redirect(svar_t *svar, char *command, int *arr_fd, int iter)
{
	pid_t pid;
	int out;

	pid = fork();
	if (pid == 0) {
		if (iter > 0)
			dup2(arr_fd[iter * 2 - 2], 0);
		out = open(command, O_WRONLY | O_TRUNC | O_CREAT,
		S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		dup2(out, 1);
		close(out);
		verify_user_command(svar, command);
		exit(svar->returnv);
	}
}

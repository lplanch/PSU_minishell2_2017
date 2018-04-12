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

	if (search_env("PATH", svar) != -1)
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
		verify_binary_command, NULL};

	if (svar->done != 0)
		return;
	for (int i = 0; diff_cmd[i] != NULL && iter == 0; i++)
		iter = (*diff_cmd[i])(svar, command);
	if (!iter) {
		start_binary_command(svar, command);
	}
}

void make_user_commands(svar_t *svar, char **acmd, int *aredir, int *arr_fd)
{
	int len = count_lines(acmd);

	for (int i = 0; acmd[i + 1] != NULL; i++)
		pipe_command(svar, acmd[i], arr_fd, (int[2]){i, len});
	if (command_is_buildtin(acmd[len - 1])) {
		verify_user_command(svar, acmd[len - 1]);
	} else {
		pipe_command(svar, acmd[len - 1], arr_fd,
		(int[2]){len - 1, len});
	}
}

void redirect_user_commands(svar_t *svar, char **arr_cmd_fd, int *arr_redir)
{
	int len = count_lines(arr_cmd_fd);
	int arr_fd[len * 2 - 2];
	int status;

	for (int i = 0; i < len * 2 - 2; i += 2)
		pipe(arr_fd + i);
	make_user_commands(svar, arr_cmd_fd, arr_redir, arr_fd);
	for (int i = 0; i < len * 2 - 2; i += 2) {
		close(arr_fd[i]);
		close(arr_fd[i + 1]);
	}
	for (int i = 0; i < len; i++)
		wait(&status);
	svar->returnv = WEXITSTATUS(status);
}

void parse_user_commands(svar_t *svar)
{
	char **arr_cmd_fd;
	int *arr_redirect;

	if (svar->done != 0)
		return;
	for (int i = 0; svar->c_cmd[i] != NULL; i++) {
		if (verify_redirect_formating(svar->c_cmd[i])) {
			arr_cmd_fd = make_table_redir_command(svar->c_cmd[i]);
			arr_redirect = make_table_int_redirect(svar->c_cmd[i]);
			redirect_user_commands(svar, arr_cmd_fd, arr_redirect);
			free_tbl(arr_cmd_fd);
			free(arr_redirect);
		} else {
			svar->returnv = 1;
		}
	}
}

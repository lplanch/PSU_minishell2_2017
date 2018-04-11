/*
** EPITECH PROJECT, 2018
** exec_outside.c
** File description:
** exec_outside_program
*/

#include "my.h"
#include "minishell2.h"

void print_core_dump_errors(int wstatus)
{
	if (wstatus == 139 || wstatus == SIGSEGV)
		my_putstrror("Segmentation fault");
	if (wstatus == SIGFPE)
		my_putstrror("Floating point exception");
	if (WCOREDUMP(wstatus))
		my_putstrror(" (core dumped)");
	if (wstatus == 139 || wstatus == SIGSEGV ||
		wstatus == SIGPIPE || WCOREDUMP(wstatus))
		my_putstrror("\n");
}

int exec_out_prm(char *c_path, char *buff, svar_t *svar)
{
	int wstatus;
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork :");
	} else if (pid == 0) {
		execve(c_path, create_table(buff), svar->c_env);
		exit(0);
	} else {
		waitpid(pid, &wstatus, 0);
		print_core_dump_errors(wstatus);
	}
	return (1);
}

int verify_path_exec(svar_t *svar, char *command, char *path_line)
{
	int result;
	char *c_path;
	char *file_name;
	char *command_name;

	command_name = get_command_without_args(command);
	file_name = my_strcat("/", command_name);
	free(command_name);
	c_path = my_strcat(path_line, file_name);
	free(file_name);
	if (access(c_path, F_OK) == 0) {
		exec_out_prm(c_path, command, svar);
		free(c_path);
		return (1);
	}
	free(c_path);
	return (0);
}

int exec_outside(svar_t *svar, char *command)
{
	int iter = 0;
	char **path_tbl;

	if (search_env("PATH", svar) == -1)
		return (0);
	path_tbl = get_path(svar);
	for (int i = 0; path_tbl[i] != NULL; i++) {
		iter = verify_path_exec(svar, command, path_tbl[i]);
		if (iter == 1) {
			svar->returnv = 0;
			free_tbl(path_tbl);
			return (1);
		}
	}
	free_tbl(path_tbl);
	return (0);
}

/*
** EPITECH PROJECT, 2018
** exec_outside.c
** File description:
** exec_outside_program
*/

#include "my.h"
#include "minishell2.h"

int print_core_dump_errors(svar_t *svar, int wstatus)
{
	if (wstatus == 139 || wstatus == SIGSEGV) {
		my_putstrror("Segmentation fault");
	} if (wstatus == 136 || wstatus == SIGFPE) {
		my_putstrror("Floating exception");
	} if (WCOREDUMP(wstatus)) {
		my_putstrror(" (core dumped)");
	} if (wstatus == 139 || wstatus == SIGSEGV ||
	wstatus == 136 || WCOREDUMP(wstatus)) {
		my_putstrror("\n");
		return (1);
	}
	return (0);
}

int exec_out_prm(char *c_path, char *buff, svar_t *svar)
{
	int wstatus;
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork");
	} else if (pid == 0) {
		execve(c_path, create_table(buff), svar->c_env);
		exit(errno);
	} else {
		waitpid(pid, &wstatus, 0);
		if (wstatus == 2048) {
			my_putstrror(c_path);
			my_putstrror(": Exec format error. ");
			my_putstrror("Wrong Architecture.\n");
			svar->returnv = 1;
		} else if (print_core_dump_errors(svar, wstatus))
			svar->returnv = wstatus;
		else
			svar->returnv = WEXITSTATUS(wstatus);
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
	if (command_name[0] != '/') {
		file_name = my_strcat("/", command_name);
		c_path = my_strcat(path_line, file_name);
		free(command_name);
		free(file_name);
	} else
		c_path = command_name;
	if (access(c_path, F_OK) == 0) {
		exec_out_prm(c_path, command, svar);
		free(c_path);
		return (1);
	}
	free(c_path);
	return (0);
}

int command_is_buildtin(char *command)
{
	char *temp = get_command_without_args(command);

	if (!my_strcmp(temp, "cd")|| !my_strcmp(temp, "env") ||
	!my_strcmp(temp, "setenv") || !my_strcmp(temp, "unsetenv") ||
	!my_strcmp(temp, "exit")) {
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

int exec_outside(svar_t *svar, char *command)
{
	int iter = 0;
	char **path_tbl;

	svar->returnv = 0;
	if (search_env("PATH", svar) == -1)
		return (0);
	path_tbl = get_path(svar);
	for (int i = 0; path_tbl[i] != NULL; i++) {
		iter = verify_path_exec(svar, command, path_tbl[i]);
		if (iter == 1) {
			free_tbl(path_tbl);
			return (1);
		}
	}
	free_tbl(path_tbl);
	return (0);
}

/*
** EPITECH PROJECT, 2018
** exec_outside.c
** File description:
** exec_outside_program
*/

#include "my.h"
#include "minishell2.h"

char **get_path(svar_t *svar)
{
	int j = 0;
	int k = 0;
	char *line = get_env(svar->c_env[search_env("PATH", svar)]);
	char **result = my_calloc(sizeof(char *) * (count_chr(line, ':') + 2));

	result[j] = malloc(sizeof(char) * (my_lstrlen(line, ':') + 1));
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ':') {
			result[j][k] = '\0';
			j += 1;
			k = 0;
			result[j] = malloc(sizeof(char) *
			(my_lstrlen(&line[i + 1], ':') + 1));
		} else
			result[j][k] = line[i];
		k = (line[i] == ':' ? 0 : k + 1);
	}
	result[j][k] = '\0';
	result[j + 1] = NULL;
	return(result);
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
	return(1);
}

int exec_outside_without_path(svar_t *svar)
{
	char *path_tbl = "/usr/bin/";
	char *c_path = my_strcat(path_tbl, svar->n_cmd);

	if (access(c_path, F_OK) == 0) {
		exec_out_prm(c_path, svar->t_cmd, svar);
		free(c_path);
		return(1);
	}
	free(c_path);
	return(0);
}

int exec_outside(svar_t *svar)
{
	int result;
	char *c_path;
	char *file_name;
	char **path_tbl = get_path(svar);

	for (int i = 0; path_tbl[i] != NULL; i++) {
		file_name = my_strcat("/", svar->n_cmd);
		c_path = my_strcat(path_tbl[i], file_name);
		if (access(c_path, F_OK) == 0) {
			exec_out_prm(c_path, svar->t_cmd, svar);
			free(file_name);
			free(c_path);
			return(1);
		}
		free(file_name);
		free(c_path);
	}
	return(0);
}

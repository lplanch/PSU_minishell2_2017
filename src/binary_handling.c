/*
** EPITECH PROJECT, 2018
** binary_handling.c
** File description:
** file to stock all functions about executing a binary
*/

#include "my.h"
#include "minishell2.h"

char *cat_both_path(char *path1, char *path2)
{
	int i = 0;
	int j = 0;
	char *result;

	for (i; path2[i] != '/' && path2[i] != '\0'; i++);
	result = (char *)my_calloc(sizeof(char) *
	(my_strlen(path1) + my_strlen(path2) - i + 1));
	for (j = 0; path1[j] != '\0'; j++)
		result[j] = path1[j];
	for (i; path2[i] != '\0'; i++) {
		result[j] = path2[i];
		j++;
	}
	result[j] = '\0';
	return(result);
}

int is_directory(char *path)
{
	struct stat sb;

	stat(path, &sb);
	return S_ISDIR(sb.st_mode);
}

int verify_permissions(char *path, svar_t *svar)
{
	if (access(path, F_OK) == 0) {
		if (access(path, X_OK) == 0 && is_directory(path) == 0) {
			return(1);
		} else {
			my_putstrror(svar->t_cmd);
			my_putstrror(": Permission denied.\n");
		}
	} else {
		my_putstrror(svar->t_cmd);
		my_putstrror(": Command not found.\n");
	}
	return(0);
}

void execute_bin(svar_t *svar)
{
	char *pwd;
	char *path;

	if (svar->t_cmd[0] == '.') {
		pwd = get_env(svar->c_env[search_env("PWD", svar)]);
		path = cat_both_path(pwd, svar->t_cmd);
		if (verify_permissions(path, svar) == 0)
			return;
		exec_out_prm(path, svar->t_cmd, svar);
		free(path);
	} else {
		path = svar->t_cmd;
		if (verify_permissions(path, svar) == 0)
			return;
		exec_out_prm(path, svar->t_cmd, svar);
	}
}

int verify_binary_command(svar_t *svar)
{
	if (svar->t_cmd[0] == '/' ||
	(svar->t_cmd[0] == '.' && svar->t_cmd[1] == '/')) {
		execute_bin(svar);
		return(1);
	}
	return(0);
}

/*
** EPITECH PROJECT, 2018
** env_verify.c
** File description:
** some randoms functions about env and verifying
*/

#include "my.h"
#include "minishell2.h"

int verify_exist_pwd(svar_t *svar)
{
	int PWD = search_env("PWD", svar);
	char *temp;
	char cwd[1024];

	if (PWD == -1) {
		if ((getcwd(cwd, sizeof(cwd))) == NULL)
			return (-1);
		temp = my_strcat("PWD=", cwd);
		svar->c_env = my_tbl_append(svar->c_env, temp);
		free(temp);
		PWD = search_env("PWD", svar);
	}
	return (PWD);
}

char **get_path(svar_t *svar)
{
	int j = 0;
	int k = 0;
	char *line = get_env(svar->c_env[search_env("PATH", svar)]);
	char **result = my_calloc(sizeof(char *) * (count_chr(line, ':') + 2));

	result[j] = my_calloc(sizeof(char) * (my_lstrlen(line, ':') + 1));
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ':') {
			j += 1;
			k = 0;
			result[j] = my_calloc(sizeof(char) *
			(my_lstrlen(&line[i + 1], ':') + 1));
		} else
			result[j][k] = line[i];
		k = (line[i] == ':' ? 0 : k + 1);
	}
	result[j + 1] = NULL;
	return (result);
}

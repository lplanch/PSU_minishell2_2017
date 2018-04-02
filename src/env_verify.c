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

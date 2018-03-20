/*
** EPITECH PROJECT, 2018
** env_handling.c
** File description:
** play with env variables and strings
*/

#include "my.h"
#include "minishell2.h"

char *get_env(char *line)
{
	int i = 0;

	while (line[i] != '=')
		i = i + 1;
	return(&line[i + 1]);
}

int compar_env(char *name, char *cmp)
{
	int j = 0;

	for (j = 0; cmp[j] != '=' && name[j] != '\0'; j++) {
		if (name[j] != cmp[j])
			return(0);
	} if (cmp[j] == '=' && name[j] == '\0')
		return(1);
	return(0);
}

int search_env(char *name, svar_t *svar)
{
	int result = -1;
	int i = 0;

	for (i = 0; svar->c_env[i] != NULL; i++) {
		if (compar_env(name, svar->c_env[i]) == 1) {
			result = i;
			return(result);
		}
	}
	return(result);
}

void print_env(char **envp)
{
	for (int i = 0; envp[i] != NULL; i++) {
		my_putstr(envp[i]);
		my_putchar('\n');
	}
}

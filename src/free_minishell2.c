/*
** EPITECH PROJECT, 2018
** free_minishell2.c
** File description:
** file to stock all frees
*/

#include "my.h"
#include "minishell2.h"

void free_svar_while(svar_t *svar)
{
	if (svar->t_all_cmd != NULL)
		free(svar->t_all_cmd);
	if (svar->c_all_cmd != NULL)
		free(svar->c_all_cmd);
	if (svar->c_cmd != NULL)
		free_tbl(svar->c_cmd);
	svar->t_all_cmd = NULL;
	svar->c_all_cmd = NULL;
	svar->c_cmd = NULL;
}

int free_svar_exit(svar_t *svar)
{
	int return_value = svar->returnv;

	free_tbl(svar->c_env);
	free(svar);
	return (return_value);
}

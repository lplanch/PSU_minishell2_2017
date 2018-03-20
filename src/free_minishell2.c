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
	if (svar->t_cmd != NULL)
		free(svar->t_cmd);
	if (svar->c_cmd != NULL)
		free(svar->c_cmd);
	if (svar->n_cmd != NULL)
		free(svar->n_cmd);
	svar->t_cmd = NULL;
	svar->c_cmd = NULL;
	svar->n_cmd = NULL;
}

void free_svar_exit(svar_t *svar)
{
	free_tbl(svar->c_env);
	free(svar);
}

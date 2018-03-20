/*
** EPITECH PROJECT, 2018
** main_minishell2.c
** File description:
** main file for minishell2
*/

#include "my.h"
#include "minishell2.h"

void verify_keyboard_exit(char *str, int *done)
{
	if (str == NULL) {
		my_putstr("exit\n");
		*done = 1;
	}
}

svar_t *init_svar(char **envp)
{
	svar_t *svar = malloc(sizeof(svar_t));
	char *path_temp;
	char cwd_temp[512];
	char *temp_dir;

	svar->c_env = my_tbldup(envp);
	if (search_env("PWD", svar) == -1) {
		temp_dir = getcwd(cwd_temp, sizeof(cwd_temp));
		path_temp = my_strcat("PWD=", temp_dir);
		free(temp_dir);
		svar->c_env = my_tbl_append(svar->c_env, path_temp);
		free(path_temp);
	}
	svar->t_cmd = NULL;
	svar->c_cmd = NULL;
	svar->n_cmd = NULL;
}

int main(int ac, char **av, char **envp)
{
	int done = 0;
	svar_t *svar = init_svar(envp);

	verify_signals();
	while (!done) {
		print_custom_prompt(svar);
		get_user_command(svar);
		verify_keyboard_exit(svar->t_cmd, &done);
		free_svar_while(svar);
	}
	free_svar_exit(svar);
	return (0);
}

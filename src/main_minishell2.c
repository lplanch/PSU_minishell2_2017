/*
** EPITECH PROJECT, 2018
** main_minishell2.c
** File description:
** main file for minishell2
*/

#include "my.h"
#include "minishell2.h"

void verify_keyboard_exit(svar_t *svar)
{
	if (svar->t_all_cmd == NULL) {
		my_putstr("exit\n");
		svar->done = 1;
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
		svar->c_env = my_tbl_append(svar->c_env, path_temp);
		free(path_temp);
	}
	svar->t_all_cmd = NULL;
	svar->c_all_cmd = NULL;
	svar->c_cmd = NULL;
	svar->done = 0;
}

int main(int ac, char **av, char **envp)
{
	svar_t *svar = init_svar(envp);

	verify_signals();
	while (!svar->done) {
		print_custom_prompt(svar);
		get_user_command(svar);
		verify_keyboard_exit(svar);
		parse_user_commands(svar);
		free_svar_while(svar);
	}
	free_svar_exit(svar);
	return (0);
}

/*
** EPITECH PROJECT, 2018
** switch_env_handling.c
** File description:
** file to stock all functions about switching env and creating env
*/

#include "my.h"
#include "minishell2.h"

void switch_env_cd_less(svar_t *svar)
{
	int PWD = verify_exist_pwd(svar);
	int OLDPWD = search_env("OLDPWD", svar);
	char *env_oldpwd;
	char *env_pwd;

	if (PWD == -1) {
		my_putstrror("Too long directory path size (max : 1024).\n");
		return;
	}
	env_oldpwd = get_env(svar->c_env[OLDPWD]);
	env_pwd = get_env(svar->c_env[PWD]);
	chdir(env_oldpwd);
	svar->c_env[OLDPWD] = my_strcat("OLDPWD=", env_pwd);
	svar->c_env[PWD] = my_strcat("PWD=", env_oldpwd);
	free(&env_oldpwd[-7]);
	free(&env_pwd[-4]);
}

void make_oldpwd_line(svar_t *svar, int PWD)
{
	int OLDPWD = search_env("OLDPWD", svar);
	char *env_oldpwd;

	env_oldpwd = my_strcat("OLDPWD=", get_env(svar->c_env[PWD]));
	if (OLDPWD == -1) {
		svar->c_env = my_tbl_append(svar->c_env, env_oldpwd);
	} else {
		free(svar->c_env[OLDPWD]);
		svar->c_env[OLDPWD] = env_oldpwd;
	}
}

void make_new_pwd(svar_t *svar, char *new_pwd)
{
	int PWD = verify_exist_pwd(svar);
	char *env_oldpwd;
	char *env_pwd;

	if (PWD == -1) {
		my_putstrror("Too long directory path size (max : 1024).\n");
		return;
	}
	make_oldpwd_line(svar, PWD);
	free(svar->c_env[PWD]);
	chdir(new_pwd);
	svar->c_env[PWD] = my_strcat("PWD=", new_pwd);
}

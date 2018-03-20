/*
** EPITECH PROJECT, 2018
** prompt_handling.c
** File description:
** play with prompt for a better minishell2
*/

#include "my.h"
#include "minishell2.h"

void print_user(svar_t *svar)
{
	int user_env = search_env("USER", svar);

	if (user_env != -1)
		my_putstr(get_env(svar->c_env[user_env]));
	else
		my_putstr("user_error");
}

void print_cwd_getcwd(svar_t *svar)
{
	int last_chr;
	char cwd[512];

	if ((getcwd(cwd, sizeof(cwd))) == NULL)
		return;
	for (int i = 0; cwd[i] != '\0'; i++) {
		if (cwd[i] == '/')
			last_chr = i + 1;
	}
	my_putstr(&cwd[last_chr]);
}

void print_cwd(svar_t *svar)
{
	int pwd_env = search_env("PWD", svar);
	int last_chr;
	char *tmp_pwd;

	if (pwd_env == -1) {
		print_cwd_getcwd(svar);
		return;
	}
	tmp_pwd = get_env(svar->c_env[pwd_env]);
	for (int i = 0; tmp_pwd[i] != '\0'; i++) {
		if (tmp_pwd[i] == '/')
			last_chr = i + 1;
	}
	my_putstr(&tmp_pwd[last_chr]);

}

void print_custom_prompt(svar_t *svar)
{
	my_putchar('[');
	print_user(svar);
	my_putchar(' ');
	print_cwd(svar);
	my_putstr("/]: ");
}

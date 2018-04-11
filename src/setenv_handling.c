/*
** EPITECH PROJECT, 2018
** setenv_handling.c
** File description:
** setenv file
*/

#include "my.h"
#include "minishell2.h"

int char_is_ok_setenv(char chr)
{
	return ((47 < chr && chr < 58 || 64 < chr && chr < 91 ||
	96 < chr && chr < 123 || chr == 95 || chr == 34 || chr == 39) ? 1 : 0);
}

int verify_setenv_chars(char *f_arg)
{
	printf("farg : \"%s\"\n", f_arg);
	if (is_letter(f_arg[0]) == 0) {
		my_putstrror("setenv: Variable name must begin");
		my_putstrror(" with a letter.\n");
		return (0);
	} for (int i = 0; f_arg[i] != '\0'; i++) {
		if (char_is_ok_setenv(f_arg[i]) == 0) {
			my_putchar(f_arg[i]);
			my_putstrror("setenv: Variable name must contain");
			my_putstrror(" alphanumeric characters.\n");
			return (0);
		}
	}
	return (1);
}

void setenv_args(svar_t *svar, char *command)
{
	char *f_arg = get_args_nbr(command, 1);
	char *s_arg = get_args_nbr(command, 2);
	char *temp;
	char *complete_line;
	int nbr_env = search_env(f_arg, svar);

	if (verify_setenv_chars(f_arg) == 1) {
		temp = my_strcat("=", s_arg);
		complete_line = my_strcat(f_arg, temp);
		free(temp);
		if (nbr_env == -1) {
			svar->c_env = my_tbl_append(svar->c_env, complete_line);
			free(complete_line);
		} else
			svar->c_env[nbr_env] = complete_line;
	} else
		svar->returnv = 1;
	free(f_arg);
	free(s_arg);
}

int main_setenv(svar_t *svar, char *command)
{
	int nbr_args = count_chr(command, ' ');

	if (nbr_args == 0) {
		print_env(svar);
	} else if (nbr_args == 2 || nbr_args == 1) {
		setenv_args(svar, command);
	} else {
		my_putstrror("setenv: Too many arguments.\n");
		svar->returnv = 1;
	}
}

int verify_setenv_command(svar_t *svar, char *command)
{
	if (!verify_command(command, "setenv"))
		return (0);
	svar->returnv = 0;
	main_setenv(svar, command);
	return (1);
}

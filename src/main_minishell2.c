/*
** EPITECH PROJECT, 2018
** main_minishell2.c
** File description:
** main file for minishell2
*/

#include "my.h"
#include "minishell2.h"

int main(int ac, char **av)
{
	int done = 0;
	char *str;

	while (!done) {
		print_custom_prompt();
		str = get_next_line(0);
		free(str);
	}
	return (0);
}

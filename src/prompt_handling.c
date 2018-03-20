/*
** EPITECH PROJECT, 2018
** prompt_handling.c
** File description:
** play with prompt for a better minishell2
*/

#include "my.h"
#include "minishell2.h"

void print_cwd(void)
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

void print_custom_prompt(void)
{
	my_putchar('[');
	print_cwd();
	my_putstr("/]: ");
}

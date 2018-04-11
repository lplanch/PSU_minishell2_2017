/*
** EPITECH PROJECT, 2018
** signals_handling.c
** File description:
** file to stock all functions about signals
*/

#include "my.h"
#include "minishell2.h"

void sig_handler(int sig_num)
{
	switch (sig_num) {
	case SIGINT:
		my_putstr("\b\b  \b\b");
		return;
	}
}

void verify_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(139, sig_handler);
	signal(SIGFPE, sig_handler);
}

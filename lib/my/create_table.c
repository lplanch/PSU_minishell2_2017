/*
** EPITECH PROJECT, 2018
** create_table.c
** File description:
** create table with str
*/

#include "my.h"

int count_nbr_words(char *str)
{
	int len = 0;
	int in_word = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (in_word == 0 && str[i] != ' ' && str[i] != '\t') {
			in_word = 1;
			len += 1;
		} else if (str[i] == ' ' || str[i] == '\t') {
			in_word = 0;
		}
	}
	return (len);
}

int *count_words_len(char *str)
{
	int nbr_words = count_nbr_words(str);
	int *len = malloc(sizeof(int) * (nbr_words));
	int current_word = 0;
	int in_word = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && str[i] != '\t' && in_word == 0)
			len[current_word] = 0;
		if (str[i] != ' ' && str[i] != '\t') {
			in_word = 1;
			len[current_word] += 1;
		} else if ((str[i] == ' ' || str[i] == '\t') && in_word == 1) {
			in_word = 0;
			current_word += 1;
		}
	}
	return (len);
}

void end_table(char **result, int cword, int cchar)
{
	if (cchar != 0) {
		result[cword][cchar] = '\0';
		result[cword + 1] = NULL;
	} else {
		result[cword] = NULL;
	}
}

void make_wbetter(char *result, int *in_word, int *cchar, char chr)
{
	*in_word = 1;
	result[*cchar] = chr;
	*cchar += 1;
}

char **create_table(char *str)
{
	int in_word = 0;
	int cword = 0;
	int cchar = 0;
	int *len = count_words_len(str);
	char **result = malloc(sizeof(char *) * (count_nbr_words(str) + 1));

	for  (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && str[i] != '\t' && in_word == 0)
			result[cword] = malloc(sizeof(char) * (len[cword] + 1));
		if (str[i] != ' ' && str[i] != '\t') {
			make_wbetter(result[cword], &in_word, &cchar, str[i]);
		} if ((str[i] == ' ' || str[i] == '\t') && in_word == 1) {
			result[cword][cchar] = '\0';
			in_word = 0;
			cword += 1;
			cchar = 0;
		}
	}
	end_table(result, cword, cchar);
	return (result);
}

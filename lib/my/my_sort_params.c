/*
** EPITECH PROJECT, 2018
** my sort params
** File description:
** sort params
*/

#include "my.h"

int count_nbr_str(char **table)
{
	int len = 0;

	while (table[len] != NULL) {
		len = len + 1;
	}
	return (len);
}

void sort_param_ezy(char **table, int i)
{
	int j = 0;
	int len = count_nbr_str(table);
	char *temp;

	while (j < len) {
		if (my_strcmp(table[i], table[j]) < 0) {
			temp = table[i];
			table[i] = table[j];
			table[j] = temp;
		} else
			j = j + 1;
	}
}

char **my_sort_params(char **table)
{
	int len = count_nbr_str(table);
	int i = 0;
	int j = 1;

	while (i < len) {
		sort_param_ezy(table, i);
		i = i + 1;
	}
	return (table);
}

/*
** EPITECH PROJECT, 2018
** my_tbl_rm.c
** File description:
** remove a string from a table
*/

#include "my.h"

char **my_tbl_rm(char **tbl, int nbr)
{
	char **result = malloc(sizeof(char *) * (count_lines(tbl)));
	int i = 0;

	if (nbr < 0) {
		free(result);
		return (tbl);
	}
	for (i = 0; i < nbr && tbl[i] != NULL; i++) {
		result[i] = my_strdup(tbl[i]);
	}
	i += 1;
	for (i; tbl[i] != NULL; i++) {
		result[i - 1] = my_strdup(tbl[i]);
	}
	result[i - 1] = NULL;
	free_tbl(tbl);
	return (result);
}

/*
** EPITECH PROJECT, 2018
** my_tbl_append.c
** File description:
** append a char to a tbl
*/

#include "my.h"

char **my_tbl_append(char **tbl, char *to_add)
{
	int i = 0;
	char **result = malloc(sizeof(char *) * (count_lines(tbl) + 2));

	while (tbl[i] != NULL) {
		result[i] = my_strdup(tbl[i]);
		i = i + 1;
	}
	result[i] = my_strdup(to_add);
	result[i + 1] = NULL;
	free_tbl(tbl);
	return (result);
}

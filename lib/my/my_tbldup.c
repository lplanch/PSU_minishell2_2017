/*
** EPITECH PROJECT, 2018
** my_tbldup.c
** File description:
** file to stock all functions about setting env
*/

#include "my.h"

char **my_tbldup(char **tbl)
{
	int i = -1;
	char **result = malloc(sizeof(char *) * (count_lines(tbl) + 1));

	while (tbl[++i] != NULL)
		result[i] = my_strdup(tbl[i]);
	result[i] = NULL;
	return (result);
}

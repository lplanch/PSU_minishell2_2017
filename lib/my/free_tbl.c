/*
** EPITECH PROJECT, 2018
** free_tbl.c
** File description:
** function to free a table who end with NULL value
*/

#include "my.h"

void free_tbl(char **tbl)
{
	for (int i = 0; tbl[i] != NULL; i++) {
		free(tbl[i]);
	}
	free(tbl);
}

/*
** EPITECH PROJECT, 2018
** count_lines.c
** File description:
** count lines of a table
*/

#include "my.h"

int count_lines(char **tbl)
{
	int result = 0;

	while (tbl[result] != NULL) {
		result = result + 1;
	}
	return (result);
}

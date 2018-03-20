/*
** EPITECH PROJECT, 2018
** count_chr_tbl.c
** File description:
**
*/

#include "my.h"

int count_chr_tbl(char **tbl, char chr)
{
	int result = 0;

	for (int y = 0; tbl[y] != NULL; y++) {
		for (int x = 0; tbl[y][x] != '\0'; x++) {
			result = result + (tbl[y][x] == chr ? 1 : 0);
		}
	}
	return (result);
}

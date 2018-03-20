/*
** EPITECH PROJECT, 2018
** my_calloc
** File description:
** my_calloc is same as calloc from the lib
*/

#include <stdlib.h>

void *my_calloc(int size)
{
	char *tbl = malloc(size + 1);

	while (size >= 0) {
		tbl[size] = 0;
		size = size - 1;
	}
	return (tbl);
}

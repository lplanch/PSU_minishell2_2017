/*
** EPITECH PROJECT, 2018
** my_putarr.c
** File description:
** print an array
*/

#include "my.h"

void my_putarr(char **array)
{
	for (int y = 0; array[y] != NULL; y++) {
		my_putstr(array[y]);
		my_putchar('\n');
	}
}

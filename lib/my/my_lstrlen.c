/*
** EPITECH PROJECT, 2018
** my_lstrlen.c
** File description:
** count chars from a str untill char == arg
*/

#include "my.h"

int my_lstrlen(char *str, char chr)
{
	int result = 0;

	while (str[result] != chr && str[result] != '\0') {
		result += 1;
	}
	return (result);
}

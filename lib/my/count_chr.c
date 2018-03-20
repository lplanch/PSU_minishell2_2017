/*
** EPITECH PROJECT, 2018
** count_chr.c
** File description:
** count chr in a str
*/

#include "my.h"

int count_chr(char *str, char chr)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == chr)
			len += 1;
	}
	return (len);
}

/*
** EPITECH PROJECT, 2018
** replace_chr.c
** File description:
** replace a character with another
*/

#include "my.h"

void replace_chr(char *str, char replace, char with)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] == replace)
			str[i] = with;
	}
}

/*
** EPITECH PROJECT, 2018
** get_str_untill.c
** File description:
** get str untill the chr given
*/

#include "my.h"

char *get_str_untill(char *str, char chr)
{
	int i = 0;
	char *result = (char *)my_calloc(sizeof(char) *
	(my_lstrlen(str, chr) + 1));

	for (i = 0; str[i] != chr && str[i] != '\0'; i++) {
		result[i] = str[i];
	}
	result[i] = '\0';
	return (result);
}

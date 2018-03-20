/*
** EPITECH PROJECT, 2018
** rm_str_untill.c
** File description:
** remove since start of string untill reached chr
*/

#include "my.h"

char *rm_str_untill(char *str, char chr)
{
	int i = 0;
	int j = 0;
	char *result;

	for (i = 0; str[i] != chr && str[i] != '\0'; i++);
	result = (char *)my_calloc(sizeof(char) * (my_strlen(str) - i + 1));
	for (i; str[i] != '\0'; i++) {
		result[j] = str[i];
		j++;
	}
	result[j] = '\0';
	return (result);
}

/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** ca ca
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
	char *str;
	int i = 0;

	while (src[i] != '\0') {
		i = i + 1;
	}
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] != '\0') {
		str[i] = src[i];
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}

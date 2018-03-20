/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse an str
*/

#include "my.h"

char *my_revstr(char *str)
{
	int i = 0;
	int len = my_strlen(str) - 1;
	char temp;

	while (i < len) {
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i = i + 1;
		len = len - 1;
	}
	str[len + 1] = '\0';
	return (str);
}

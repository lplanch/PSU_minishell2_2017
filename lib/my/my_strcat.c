/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my str cat assemble 2 char *
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	char *result = (char *)my_calloc(sizeof(char) * (len1 + len2 + 1));

	for (i = 0; str1[i] != '\0'; i++) {
		result[i] = str1[i];
	} for (j = 0; str2[j] != '\0'; j++) {
		result[i + j] = str2[j];
	}
	result[i + j] = '\0';
	return (result);
}

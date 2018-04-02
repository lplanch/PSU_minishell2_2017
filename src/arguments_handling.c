/*
** EPITECH PROJECT, 2018
** arguments_handling.c
** File description:
** play with commands args
*/

#include "my.h"
#include "minishell2.h"

char *get_args(char *buffer)
{
	char *result;
	int iter = 0;

	while (buffer[iter] != '\0' && buffer[iter] != ' ')
		iter++;
	if (buffer[iter] == '\0')
		return (NULL);
	iter += 1;
	result = my_calloc(sizeof(char) * (my_strlen(buffer) + 1));
	for (int i = 0; buffer[iter] != '\0'; i++) {
		result[i] = buffer[iter];
		iter += 1;
	}
	return (result);
}

char *get_args_nbr(char *buffer, int number)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *result;

	for (i = 0; j < number && buffer[i] != '\0'; i++) {
		if (buffer[i] == ' ')
			j += 1;
	}
	j = i;
	for (i; buffer[i] != '\0' && buffer[i] != ' '; i++);
	result = malloc(sizeof(char) * (i - j + 1));
	for (j; buffer[j] != '\0' && buffer[i] != ' '; j++) {
		result[k] = buffer[j];
		k += 1;
	}
	result[k] = '\0';
	return (result);
}

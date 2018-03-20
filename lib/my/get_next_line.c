/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** 2nd try
*/

#include "my.h"

char *my_strcat_nl(char *str1, char *str2)
{
	int j = 0;
	char *result = malloc(sizeof(char) *
	(my_strlen(str1) + my_strlen(str2) + 1));

	if (result == NULL)
		return(NULL);
	for (int i = 0; str1[i] != '\0'; i++) {
		result[j] = str1[i];
		j++;
	}
	for (int i = 0; str2[i] != '\0'; i++) {
		result[j] = str2[i];
		j++;
	}
	result[j] = '\0';
	free(str1);
	return (result);
}

char *increment_buff(char *result, char *buffer, char *resul)
{
	int i = 0;

	result[-1] = '\0';
	for (i; result[i] != '\0'; i++)
		buffer[i] = result[i];
	for (i; i < READ_SIZE; i++)
		buffer[i] = '\0';
	return (resul);
}

int verify_buffer(char **result, char *buffer)
{
	int i = 0;
	char *temp;

	if (buffer[0] != '\0' && result[0] != NULL) {
		result[0] = my_strcat(result[0], buffer);
		for (i = 0; result[0][i] != '\n' && result[0][i] != '\0'; i++);
		if (result[0][i] == '\n') {
			increment_buff(&result[0][i + 1], buffer, result[0]);
			return (1);
		}
		for (int j = 0; j < READ_SIZE; j++)
			buffer[j] = '\0';
	}
	return (0);
}

char *get_next_line(int fd)
{
	int i = 0;
	int sz;
	static char buffer[READ_SIZE];
	char *result = malloc(sizeof(char) * (1));

	if (result != NULL)
		result[0] = '\0';
	if (verify_buffer(&result, buffer) == 1)
		return (result);
	while ((sz = read(fd, buffer, READ_SIZE)) > 0 && result != NULL) {
		result = my_strcat_nl(result, buffer);
		if (result == NULL)
			return (NULL);
		for (i = 0; result[i] != '\n' && result[i] != '\0'; i++);
		if (result[i] == '\n' || result[i] == '\0' && sz < READ_SIZE)
			return (increment_buff(&result[i + 1], buffer, result));
		for (int j = 0; j < READ_SIZE; j++)
			buffer[j] = '\0';
	}
	return (NULL);
}

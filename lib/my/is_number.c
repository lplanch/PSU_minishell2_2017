/*
** EPITECH PROJECT, 2018
** is_number.c
** File description:
** do the number is a number ?
*/

int is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (i == 0 && str[i] == '-')
			i = i + 1;
		if (str[i] < 47 || 58 < str[i])
			return (0);
	}
	return (1);
}

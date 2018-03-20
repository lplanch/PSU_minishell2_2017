/*
** EPITECH PROJECT, 2018
** str_to_int.c
** File description:
** convert a string to int
*/

#include "my.h"

int str_to_int(char *str)
{
	int i = my_strlen(str) - 1;
	int dis = 1;
	int result = 0;
	int isNeg = 0;
	int last = -1;

	if (str[0] == '-') {
		isNeg = 1;
		last = 0;
	}
	while (i != last) {
		result = result + ((str[i] - 48) * dis);
		dis = dis * 10;
		i = i - 1;
	}
	if (isNeg == 1)
		result = result * -1;
	return (result);
}

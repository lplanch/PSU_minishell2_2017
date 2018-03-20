/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** get the str len
*/

#include <unistd.h>

int my_strlen(char const *str)
{
	int nbchr = 0;

	while (str[nbchr] != '\0') {
		nbchr = nbchr + 1;
	}
	return (nbchr);
}

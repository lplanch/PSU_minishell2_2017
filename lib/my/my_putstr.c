/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr print a string
*/

#include "my.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

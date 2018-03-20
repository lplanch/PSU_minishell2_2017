/*
** EPITECH PROJECT, 2017
** my_put_strror.c
** File description:
** print a string on error output
*/

#include "my.h"

void my_putstrror(char *str)
{
	write(2, str, my_strlen(str));
}

/*
** EPITECH PROJECT, 2018
** is_letter.c
** File description:
** verify if a char is a letter
*/

#include "my.h"

int is_letter(char chr)
{
	if (chr < 65 || 90 < chr && chr < 97 || 122 < chr)
		return (0);
	return (1);
}

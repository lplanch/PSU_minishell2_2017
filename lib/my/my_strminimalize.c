/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** task 09
*/

char *my_str_minimalize(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (str[i] != '\0') {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
		i = i + 1;
	}
	return (str);
}

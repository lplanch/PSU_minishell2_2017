/*
** EPITECH PROJECT, 2018
** my_nbrlen.c
** File description:
** count nbr of chr of an int
*/

int my_nbrlen(int nbr)
{
	int i = 0;
	long int dis = 1;

	if (nbr < 0) {
		nbr = nbr * -1;
		i = i + 1;
	} else if (nbr == 0)
		return (1);
	while (dis < nbr) {
		dis = dis * 10;
		i = i + 1;
	}
	return (i);
}

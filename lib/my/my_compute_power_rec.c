/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** caca
*/

int recu_power(int nb, int p, int i)
{
	if (p != 1) {
		nb = nb * i;
		p = p - 1;
		nb = recu_power(nb, p, i);
	}
	return (nb);
}

int my_compute_power_rec(int nb, int p)
{
	int i = nb;

	if (p == 0) {
		return (1);
	} if (p < 0) {
		return (0);
	} if (p != 1){
		nb = recu_power(nb, p, i);
		return (nb);
	}
}

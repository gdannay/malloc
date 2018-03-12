/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:39:19 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/12 14:52:45 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*static void		nb_fill(unsigned long long nb, char *new, int tail, char *base)
{
	if (nb >= (unsigned long long)ft_strlen(base))
		nb_fill(nb / (unsigned long long)ft_strlen(base), new, tail - 1, base);
	new[tail] = base[nb % (unsigned long long)ft_strlen(base)];
}*/

void			print_mem(void *ptr)
{
	int	n;
	int	taille;

	n = (int)ptr;
	taille = 0;
	while (n)
	{
		n /= 16;
		taille++;
	}
	dprintf(1, "HAHA = %d", n);
//	nb_fill(tmp->unb, new, taille - 1, base);
}

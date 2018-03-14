/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:39:19 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/14 15:05:44 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static unsigned long	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void				ft_putnbr_base(unsigned long nb,
						char *base, unsigned int base_size)
{
	if (nb >= base_size)
		ft_putnbr_base(nb / base_size, base, base_size);
	write(1, &(base[nb % base_size]), 1);
}

void					print_map(t_map *map)
{
	if (map->type == TINY)
		write(1, "TINY : ", 7);
	else if (map->type == SMALL)
		write(1, "SMALL : ", 8);
	else if (map->type == LARGE)
		write(1, "LARGE : ", 8);
	write(1, "0x", 2);
	ft_putnbr_base((unsigned long)map, HEXAMAJ, ft_strlen(HEXAMAJ));
	write(1, "\n", 1);
}

void					print_block(t_block *block)
{
	write(1, "0x", 2);
	ft_putnbr_base((unsigned long)((char *)block + SIZE_BLOCK),
					HEXAMAJ, ft_strlen(HEXAMAJ));
	write(1, " - ", 3);
	write(1, "0x", 2);
	ft_putnbr_base((unsigned long)((char *)block + SIZE_BLOCK + block->size),
				HEXAMAJ, ft_strlen(HEXAMAJ));
	write(1, " : ", 3);
	ft_putnbr_base((unsigned long)block->size, DECI, ft_strlen(DECI));
	write(1, " octets\n", 8);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:47:44 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 19:12:24 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nbr)
{
	int	i;
	int	neg;
	int	n;

	i = 0;
	neg = 0;
	n = 0;
	while ((nbr[i] >= 8 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	if (nbr[i] == '-')
		neg = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] != '\0' && nbr[i] >= '0' && nbr[i] <= '9')
	{
		n = n * 10 - (nbr[i] - '0');
		i++;
	}
	if (neg == 1)
		return (n);
	return (-n);
}

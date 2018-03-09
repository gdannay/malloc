/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:49:08 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:50:12 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	int i;

	i = -1;
	if (tab && *tab)
	{
		while ((*tab)[++i])
			ft_strdel(&(*tab)[i]);
		free(*tab);
		*tab = NULL;
	}
}

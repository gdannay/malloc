/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:31:13 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/09 19:00:22 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_zone_type(size_t size)
{
	if (size <= MAX_TINY)
		return (TINY);
	else if (size <= MAX_SMALL)
		return (SMALL);
	return (LARGE);
}

t_block	*parse_block(size_t size, t_block *block)
{
	t_block	*tmp;

	tmp = block;
	while (tmp && (tmp->free != 1 || tmp->size <= size))
		tmp = tmp->next;
	return (tmp);
}

t_block	*get_free_block(size_t size, t_zone *first_zone)
{
	t_zone	*tmp;
	t_block	*free_block;
	int		zone_type;

	tmp = first_zone;
	zone_type = get_zone_type(size);
	free_block = NULL;
	while (tmp && !free_block && zone_type != LARGE)
	{
		if (tmp->type == zone_type)
			free_block = parse_block(size, tmp->block);
		tmp = tmp->next;
	}
	if (!tmp || zone_type == LARGE)
		free_block = create_new_zone(first_zone, size, zone_type);
	return (free_block);
}

void	*ft_malloc(size_t size)
{
	static t_zone	*first_zone = NULL;
	t_block			*new;

	new = get_free_block(size, first_zone);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:44:03 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/09 19:00:17 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_alloc_size(size_t size)
{
	if (size <= MAX_TINY)
		return (SIZE_TINY);
	else if (size <= MAX_SMALL)
		return (SIZE_SMALL);
	return (size);
}

t_block	*create_block(t_zone *new, size_t size)
{
	t_block	*new_block;

	new_block = (t_block *)(new + SIZE_ZONE);
	new_block->size = size;
	new_block->free = 0;
	new_block->next= NULL;
	return (new_block);
}

t_block	*create_new_zone(t_zone *first_zone, size_t size, int type)
{
	t_zone	*new;
	t_zone	*tmp;
	t_block	*new_block;
	int		alloc_size;

	alloc_size = get_alloc_size(size);
	tmp = first_zone;
	if ((new = (t_zone *)mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	new->type = type;
	new->next = NULL;
	if (first_zone == NULL)
		first_zone = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	new_block = create_block(new, size);
	new->block = new_block;
	return (new_block);
}

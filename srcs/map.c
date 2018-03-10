/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:44:03 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/10 16:28:59 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_alloc_size(size_t size)
{
	if (size <= MAX_TINY)
		return (SIZE_TINY);
	else if (size <= MAX_SMALL)
		return (SIZE_SMALL);
	return (size + SIZE_MAP + SIZE_BLOCK);
}

t_map	**get_first_map(void)
{
	static t_map	*map = NULL;

	return (&map);
}

int		get_map_type(size_t size)
{
	if (size <= MAX_TINY)
		return (TINY);
	else if (size <= MAX_SMALL)
		return (SMALL);
	return (LARGE);
}

void	arrange_map(t_block *block, size_t size)
{
	t_block	*tmp;

	tmp = (t_block *)((char *)block + SIZE_BLOCK + size);
	tmp->next = block->next;
	block->next = tmp;
	tmp->size = block->size - SIZE_BLOCK - size;
	tmp->free = 1;
}

t_map	*create_new_map(t_map **first_map, size_t size, int type)
{
	t_map	*new;
	t_map	*tmp;
	int		alloc_size;

	alloc_size = get_alloc_size(size);
	tmp = *first_map;
	if ((new = (t_map *)mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	new->type = type;
	new->next = NULL;
	if (*first_map == NULL)
		*first_map = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:43:13 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/14 15:14:51 by gdannay          ###   ########.fr       */
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

void	delete_map(t_map **first, t_map *map)
{
	if (map->prev == NULL)
		*first = map->next;
	else if (map->next == NULL)
		map->prev->next = NULL;
	else
	{
		map->prev->next = map->next;
		map->next->prev = map->prev;
	}
	munmap((void *)map, map->block->size + SIZE_MAP + SIZE_BLOCK);
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
	if ((new = (t_map *)mmap(0, alloc_size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	if (*first_map == NULL)
		*first_map = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

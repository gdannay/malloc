/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:51:51 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/12 14:14:24 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*create_new_block(t_map **first_map, t_map **map, size_t size, int map_type)
{
	t_block	*free_block;

	if (((*map) = create_new_map(first_map, size, map_type)) == NULL)
		return (NULL);
	free_block = (t_block *)((char *)(*map) + SIZE_MAP);
	free_block->next = NULL;
	free_block->size = get_alloc_size(size) - SIZE_MAP - SIZE_BLOCK;
	(*map)->block = free_block;
	free_block->free = 0;
	return (free_block);
}

static t_block	*parse_block(size_t size, t_block *block)
{
	t_block	*tmp;

	tmp = block;
	while (tmp && (tmp->free != 1 || tmp->size <= size))
		tmp = tmp->next;
	return (tmp);
}

t_block	*get_free_block(size_t size)
{
	t_map	*map;
	t_map	**first_map;
	t_block	*free_block;
	int		map_type;

	first_map = get_first_map();
	map = *first_map;
	map_type = get_map_type(size);
	if (map_type == LARGE)
		return (create_new_block(first_map, &map, size, map_type));
	while (map)
	{
		if (map->type == map_type && (free_block = parse_block(size, map->block)))
			break ;
		map = map->next;
	}
	if (!map && !(free_block = create_new_block(first_map, &map, size, map_type)))
		return (NULL);
	if (free_block->size != size)
		arrange_map(free_block, size);
	free_block->size = size;
	free_block->free = 0;
	return (free_block);
}

void	fusion_block(t_map *map)
{
	t_block	*tmp;
	t_map	**first;

	if (!map)
		return ;
	first = get_first_map();
	tmp = map->block;
	while (tmp)
	{
		if (tmp->free && tmp->next && tmp->next->free)
		{
			tmp->size = tmp->size + tmp->next->size + SIZE_BLOCK;
			tmp->next = tmp->next->next;
			tmp = map->block;
		}
		else
			tmp = tmp->next;
	}
	if (map->block->next == NULL && map->block->free == 1)
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
}

t_map		*search_map(void *ptr)
{
	t_map	**map;
	t_block	*block;
	t_map	*tmp;

	if (!ptr)
		return (NULL);
	map = get_first_map();
	tmp = *map;
	while (tmp)
	{
		block = tmp->block;
		while (block)
		{
			if ((char *)block + SIZE_BLOCK == ptr)
				return (tmp);
			block = block->next;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

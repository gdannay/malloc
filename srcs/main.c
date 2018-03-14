/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:10:00 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/14 15:22:57 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_block			*new;

	if (size > 0)
	{
		if ((new = get_free_block(size)) == NULL)
			return (NULL);
		return ((void *)((char *)new + SIZE_BLOCK));
	}
	else
		return (NULL);
}

void	ft_free(void *ptr)
{
	t_block	*block;
	t_map	*tmp;

	if ((tmp = search_map(ptr)) == NULL)
		return ;
	block = tmp->block;
	while (block && (char *)block + SIZE_BLOCK != ptr)
		block = block->next;
	block->free = 1;
	fusion_block(tmp);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_map	*map;

	if (!ptr)
		return (ft_malloc(size));
	else if (size == 0)
		ft_free(ptr);
	if ((map = search_map(ptr)) == NULL)
		return (ptr);
	else
		return (realloc_mem(map, ptr, size));
}

void	show_alloc_mem(void)
{
	t_map	**first;
	t_map	*map;
	t_block	*block;

	first = get_first_map();
	if (*first == NULL)
	{
		write(1, "No allocated memory!\n", 21);
		return ;
	}
	map = *first;
	while (map)
	{
		print_map(map);
		block = map->block;
		while (block)
		{
			if (block->free == 0)
				print_block(block);
			block = block->next;
		}
		map = map->next;
	}
}

t_map	**get_first_map(void)
{
	static t_map	*map = NULL;

	return (&map);
}

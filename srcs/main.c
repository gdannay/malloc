/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:31:13 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/12 14:55:32 by gdannay          ###   ########.fr       */
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
	t_block	*block;
	t_block	*new_block;
	t_map	*tmp;

	if (!ptr)
		return (ft_malloc(size));
	else if (size == 0)
		ft_free(ptr);
	if ((tmp = search_map(ptr)) == NULL)
		return (ptr);
	block = tmp->block;
	while (block && (char *)block + SIZE_BLOCK != ptr)
		block = block->next;
	if (block->next && block->next->free == 1
		&& block->size + block->next->size - SIZE_BLOCK >= size)
	{
		block->size = block->size + block->next->size;
		block->next = block->next->next;
		arrange_map(block, size);
		block->size = size;
		return (ptr);
	}
	else
	{
		if ((new_block = ft_malloc(size)) == NULL)
			return (NULL);
		new_block = (t_block *)ft_memcpy(new_block, (char *)block + SIZE_BLOCK, block->size);
		ft_free(ptr);
	}
	return ((void *)((char *)new_block + SIZE_BLOCK));
}

void	show_alloc_mem()
{
	t_map	**first;
	t_map	*map;
	t_block	*block;

	first = get_first_map();
	map = *first;
	while (map)
	{
		if (map->type == TINY)
			printf("TINY");
		else if (map->type == SMALL)
			printf("SMALL");
		else if (map->type == LARGE)
			printf("LARGE");
		block = map->block;
		printf(" : %p %ld\n", (void *)map, (void *)block - (void *)map);
		while (block)
		{
			if (block->free == 0)
			{
//				print_mem(block);
				ft_printf("%p - %p : %zu octets\n", (void *)((char *)block + SIZE_BLOCK),
						(void *)((char *)block + SIZE_BLOCK + block->size), block->size);
			}
			else
			{
//				print_mem(block);
				
				ft_printf("FREE: %p - %p : %zu octets\n", (void *)((char *)block + SIZE_BLOCK),
						(void *)((char *)block + SIZE_BLOCK + block->size), block->size);
			}
			//			if (block->next)
			//				printf("TEST = %ld\n", ((char *)block->next - (char *)block - SIZE_BLOCK));
			//			else
			//				printf("TEST = %zu\n", block->size);
			block = block->next;
		}
		map = map->next;
	}

}

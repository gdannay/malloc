/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:21:55 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/14 15:09:42 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destb;
	unsigned char	*srcb;

	i = 0;
	destb = (unsigned char *)dest;
	srcb = (unsigned char *)src;
	while (i < n)
	{
		destb[i] = srcb[i];
		i++;
	}
	return (dest);
}

void	*realloc_mem(t_map *map, void *ptr, size_t size)
{
	t_block	*block;
	t_block	*new_block;

	block = map->block;
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
		new_block = (t_block *)ft_memcpy(new_block,
				(char *)block + SIZE_BLOCK, block->size);
		ft_free(ptr);
	}
	return ((void *)((char *)new_block + SIZE_BLOCK));
}

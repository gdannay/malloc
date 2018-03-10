/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:31:13 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/10 16:05:39 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_block			*new;

	new = get_free_block(size);
	return ((void *)((char *)new + SIZE_BLOCK));
}

void	show_alloc_mem()
{
	t_map	**map;
	t_block	*block;

	map = get_first_map();
	while (*map)
	{
		if ((*map)->type == TINY)
			printf("TINY");
		else if ((*map)->type == SMALL)
			printf("SMALL");
		else if ((*map)->type == LARGE)
			printf("LARGE");
		block = (*map)->block;
		printf(" : %p %ld\n", (void *)(*map), (void *)block - (void *)(*map));
		while (block)
		{
			if (block->free == 0)
				printf("%p - %p : %zu octets\n", (void *)((char *)block + SIZE_BLOCK),
						(void *)((char *)block + SIZE_BLOCK + block->size), block->size);
			if (block->next)
				printf("TEST = %ld\n", ((char *)block->next - (char *)block - SIZE_BLOCK));
			else
				printf("TEST = %zu\n", block->size);
			block = block->next;
		}
		(*map) = (*map)->next;
	}

}

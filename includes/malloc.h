/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:25:57 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/14 15:17:30 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>

# define SIZE_TINY (2 * getpagesize())
# define MAX_TINY 256

# define SIZE_SMALL (8 * getpagesize())
# define MAX_SMALL 1024

# define SIZE_BLOCK (sizeof(struct s_block))
# define SIZE_MAP (sizeof(struct s_map))

# define DECI "0123456789"
# define HEXAMAJ "0123456789ABCDEF"

typedef enum		e_map_type
{
	TINY,
	SMALL,
	LARGE
}					t_map_type;

typedef struct		s_block
{
	size_t			size;
	int				free;
	struct s_block	*next;
}					t_block;

typedef struct		s_map
{
	int				type;
	t_block			*block;
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

void				*ft_malloc(size_t size);
int					get_map_type(size_t size);
int					get_alloc_size(size_t size);
t_block				*get_free_block(size_t size);
t_map				**get_first_map(void);
t_map				*create_new_map(t_map **first_map, size_t size, int type);
t_block				*alloc_block(t_map *map);
void				arrange_map(t_block *block, size_t size);
void				show_alloc_mem(void);
void				ft_free(void *ptr);
void				fusion_block(t_map *map);
void				*ft_realloc(void *ptr, size_t size);
t_map				*search_map(void *ptr);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				print_map(t_map *map);
void				print_block(t_block *block);
void				*realloc_mem(t_map *map, void *ptr, size_t size);
void				delete_map(t_map **first, t_map *map);

#endif

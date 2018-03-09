/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:25:57 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/09 18:51:44 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define SIZE_TINY (2 * getpagesize())
# define MAX_TINY 128

# define SIZE_SMALL (16 * getpagesize())
# define MAX_SMALL 1024

# define SIZE_BLOCK (sizeof(struct s_block))
# define SIZE_ZONE (sizeof(struct s_zone))

typedef enum		e_zone_type
{
	TINY,
	SMALL,
	LARGE
}					t_zone_type;

typedef struct		s_block
{
	size_t			size;
	int				free;
	struct s_block	*next;
}					t_block;

typedef struct		s_zone
{
	int				type;
	int				rest;
	t_block			*block;
	struct s_zone	*next;
}					t_zone;

void			*ft_malloc(size_t size);
t_block			*create_new_zone(t_zone *first_zone, size_t size, int type);

#endif

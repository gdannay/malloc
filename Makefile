# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 16:14:24 by gdannay           #+#    #+#              #
#    Updated: 2018/03/14 15:40:26 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	=	libft_malloc_$(HOSTTYPE).so

SRCS	=	srcs/main.c			\
			srcs/map.c			\
			srcs/block.c		\
			srcs/realloc.c		\
			srcs/print_mem.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ln -s $(NAME) libft_malloc.so

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean	:	
			rm -rf $(OBJS)

fclean	:	
			rm -rf libft_malloc.so
			rm -rf $(OBJS)
			rm -rf $(NAME)

re		:	fclean all

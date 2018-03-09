# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 16:14:24 by gdannay           #+#    #+#              #
#    Updated: 2018/03/09 18:07:48 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_malloc.a

SRCS	=	srcs/malloc.c		\
			srcs/zone.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes

LFLAGS	=	-L libft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			ar rc $(NAME) $(OBJS)
			$(CC) main.c $(NAME)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean	:	
			make clean -C libft
			rm -rf $(OBJS)

fclean	:	
			make fclean -C libft
			rm -rf $(OBJS)
			rm -rf $(NAME)

re		:	fclean all

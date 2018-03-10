# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 16:14:24 by gdannay           #+#    #+#              #
#    Updated: 2018/03/10 14:38:44 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_malloc.a

SRCS	=	srcs/main.c			\
			srcs/map.c			\
			srcs/block.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes

LFLAGS	=	-L libft -g3 -fsanitize=address

all		:	$(NAME)

$(NAME)	:	$(OBJS) main.o
			make -C libft
			ar rc $(NAME) $(OBJS)
			$(CC) main.o $(NAME) $(LFLAGS)

main.o	:	main.c
			$(CC) -o $@ -c $< $(CFLAGS)

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

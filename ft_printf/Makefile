# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 18:49:57 by notahtah          #+#    #+#              #
#    Updated: 2023/10/24 16:03:35 by notahtah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

LIBFT		=		libft.a

LIBFT_PATH	=		libft

CC			=		cc

CFLAGS		=		-Wall -Wextra -Werror

SRCS		=		ft_printf.c			\
					ft_print_chars.c	\
					ft_print_integer.c	\
					ft_print_hex.c		\
					ft_print_pointer.c	\

OBJS		=		$(SRCS:%.c=%.o)

$(NAME):	
			make -C $(LIBFT_PATH) all
			cp $(LIBFT_PATH)/$(LIBFT) $(NAME)
			$(CC) $(CFLAGS) -c $(SRCS)
			ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			rm -f $(OBJS)
			cd $(LIBFT_PATH) && make clean

fclean: 	clean
			rm -f $(NAME)
			cd $(LIBFT_PATH) && make fclean

re:			fclean all

.PHONY:		all clean fclean re
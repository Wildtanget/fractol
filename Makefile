# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:30:21 by notahtah          #+#    #+#              #
#    Updated: 2024/05/21 20:20:43 by notahtah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fractol

SRC 	= 	colors.c \
			fractals.c \
			fractol.c \
			hooks.c \
			init.c \
			math_utils.c \
			render.c \
			string_utils.c \

OBJ				=	$(SRC:%.c=%.o)

LIBFTPRINTF_DIR	=	./ft_printf/
LIBFTPRINTF		=	libftprintf.a

MLXDIR	=	./minilibx/
MLX		=	libmlx.a

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
LINK	=	-lX11 -lXext -lm

White="\033[0m"
Gray="\033[0;30m"
Green="\033[0;32m"

all: $(NAME)
		
$(NAME): $(OBJ)
		make -C $(LIBFTPRINTF_DIR) --no-print-directory
		@echo $(Gray) "Creating MiniLibX..." $(White)
		make -C $(MLXDIR) --no-print-directory
		@echo $(Gray) "Creating $(NAME)..." $(White)
		$(CC) $(FLAGS) $(SRC) $(MLXDIR)$(MLX) $(LIBFTPRINTF_DIR)$(LIBFTPRINTF) $(LINK) -o $(NAME)
		@echo $(Green) "Succesfully created $(NAME)!" $(White)

clean:
		@echo $(Gray) "Removing all objective files..." $(White)
		rm -f $(OBJ)
		@echo $(Gray) "Removing all MiniLibX objective files..." $(White)
		make -C $(MLXDIR) clean --no-print-directory
		make -C $(LIBFTPRINTF_DIR) clean --no-print-directory
		@echo $(Green) "All object files have been removed." $(White)

fclean: clean
		@echo $(Gray) "Removing $(NAME)..." $(White)
		make -C $(LIBFTPRINTF_DIR) fclean --no-print-directory
		rm -f $(NAME)
		@echo $(Green) "All program files have been removed." $(White)

re: fclean all

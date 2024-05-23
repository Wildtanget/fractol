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

#==============================================================================#
#                                 Program Name								   #
#==============================================================================#
NAME 			= 	fractol

#==============================================================================#
#                                 Source Files								   #
#==============================================================================#
SRC_DIR			=	./src/
SRC 			= 	$(SRC_DIR)colors.c											\
					$(SRC_DIR)fractals.c 										\
					$(SRC_DIR)fractol.c											\
					$(SRC_DIR)hooks.c											\
					$(SRC_DIR)init.c											\
					$(SRC_DIR)math_utils.c										\
					$(SRC_DIR)render.c											\
					$(SRC_DIR)string_utils.c									\
					$(SRC_DIR)settings.c										\
					$(SRC_DIR)arg_check.c

SRC_BONUS_DIR	= 	./src_bonus/
SRC_BONUS		=	$(SRC_BONUS_DIR)colors_bonus.c								\
					$(SRC_BONUS_DIR)fractals_bonus.c 							\
					$(SRC_BONUS_DIR)fractol_bonus.c								\
					$(SRC_BONUS_DIR)hooks_bonus.c								\
					$(SRC_BONUS_DIR)init_bonus.c								\
					$(SRC_BONUS_DIR)math_utils_bonus.c							\
					$(SRC_BONUS_DIR)render_bonus.c								\
					$(SRC_BONUS_DIR)string_utils_bonus.c						\
					$(SRC_BONUS_DIR)settings_bonus.c							\
					$(SRC_BONUS_DIR)arg_check_bonus.c

#==============================================================================#
#                                 Objective Files							   #
#==============================================================================#
OBJ_DIR			=	./obj/
OBJ_BONUS_DIR 	=	./obj_bonus/
OBJ         	=   $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_BONUS		=   $(SRC_BONUS:$(SRC_BONUS_DIR)%.c=$(OBJ_BONUS_DIR)%.o)

#==============================================================================#
#                                 External Archives							   #
#==============================================================================#
LIBFT_DIR		=	./libft/
LIBFT			=	$(LIBFT_DIR)libft.a

MLX_DIR			=	./minilibx/
MLX				=	$(MLX_DIR)libmlx.a

#==============================================================================#
#                                 Compiler Options							   #
#==============================================================================#
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LINK			=	-lX11 -lXext -lm

#==============================================================================#
#                                 Colors									   #
#==============================================================================#
White			=	"\033[0m"
Green			=	"\033[0;32m"
Cyan        	=   "\033[0;36m"
Yellow      	=   "\033[0;33m"
Red         	=   "\033[0;31m"

#==============================================================================#
#                                 Targets									   #
#==============================================================================#

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Building Fractol..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(LINK) -o $(NAME)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Fractol is ready to be used!" $(White)
		@echo $(Cyan) "============================================================" $(White)

all: bonus

bonus: $(LIBFT) $(MLX) $(OBJ_BONUS_DIR) $(OBJ_BONUS)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Building Fractol..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(LIBFT) $(LINK) -o $(NAME)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Fractol is ready to be used!" $(White)
		@echo $(Cyan) "============================================================" $(White)
		
$(OBJ_DIR):
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Compiling all objective files..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		mkdir $(OBJ_DIR)

$(OBJ_BONUS_DIR):
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Compiling all objective files..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		mkdir $(OBJ_BONUS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Building LibFT..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Green) "Building MiniLibX..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		make -C $(MLX_DIR) --no-print-directory

clean:
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Removing all objective files..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_BONUS_DIR)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Removing all MiniLibX objective files..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		make -C $(MLX_DIR) clean --no-print-directory
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Removing all LibFT objective files..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		make -C $(LIBFT_DIR) clean --no-print-directory
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "All object files have been removed." $(White)
		@echo $(Cyan) "============================================================" $(White)

fclean: clean
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Removing LibFT..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		make -C $(LIBFT_DIR) fclean --no-print-directory
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Removing Fractol..." $(White)
		@echo $(Cyan) "============================================================" $(White)
		rm -f $(NAME)
		@echo $(Cyan) "============================================================" $(White)
		@echo $(Red) "Fractol and all external libraries have been removed." $(White)
		@echo $(Cyan) "============================================================" $(White)

re: fclean $(NAME)

norm:
	norminette inc libft src src_bonus

.PHONY: all fclean clean re norm

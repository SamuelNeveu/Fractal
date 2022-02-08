# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 16:19:27 by saneveu           #+#    #+#              #
#    Updated: 2020/01/06 16:05:40 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fractol

# src / obj files
SRC		= 	main.c \
			algo.c \
			draw.c \
			setup.c \
			exit.c \
			event.c \
			color.c \
			color2.c \
			display.c \
			event_tool.c \
			buddhabrot.c \
			tools.c \
			color_tools.c \
			palette.c \
			event_mouse.c \
			event_color.c \
			algo2.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc -Ofast 
CFLAGS	= -Wall -Wextra -Werror

# pthread lib
	PTH_LIB = -lpthread -D_REENTRANT 

# mlx library
MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L ./minilibx -l mlx -lXext -lX11 -L/usr/X11/lib # -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft ##-lpthread

# directories
SRCDIR	= ./srcs/
INCDIR	= ./include/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(MLX_LIB) $(PT_LNK) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "-->	Object-Compile"

$(FT_LIB):
	@make -C $(FT)
	@echo "=====	libft	====="
	@echo "\33[1;32mOk\33[0m"

$(MLX_LIB):
	@make -C $(MLX)
	@echo "=====	MiniLibX   ====="
	@echo "\33[1;32mOk\33[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) $(PTH_LIB) -lm -o $(NAME)
	@echo "\33[1;5;32mit's good\33][0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "=====	Objects		====="
	@echo "\33[33mClean.\33[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "=====	Everything	====="
	@echo "\33[33mClean.\33[0m"

re: fclean all

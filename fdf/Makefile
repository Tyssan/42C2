# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 15:59:52 by tbrunier          #+#    #+#              #
#    Updated: 2024/10/09 23:09:45 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME = fdf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -O0#valgrind_debug_flags

LIBX_PATH	= ./minilibx-linux/
LIBX_NAME	= libmlx.a
MLX_SETTING	= -l mlx -l Xext -l X11

INCLUDE		= include/
SRC_PATH	= src/
OBJ_PATH	= obj/
LIBFT_PATH	= src/libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a

################################################################################
## SOURCES

SRC_FILES	=	main.c
LIBSX		=	$(addprefix $(LIBX_PATH),$(LIBX_NAME))
SRCS		=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

################################################################################
## RULES

all: libft libmlx $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBSX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft -L$(LIBX_PATH) $(MLX_SETTING)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBX_PATH) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

libft:
	$(MAKE) -C $(LIBFT_PATH)

libmlx:
	$(MAKE) -C $(LIBX_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(LIBX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 16:28:13 by tbrunier          #+#    #+#              #
#    Updated: 2024/09/23 02:24:05 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME = push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -O0#valgrind_debug_flags

INCLUDE		= include/
LIBFT_INC	= src/libft/include/
SRC_PATH	= src/
OBJ_PATH	= obj/
LIBFT_PATH	= src/libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a

################################################################################
## SOURCES

SRC_FILES	=	init_a_to_b.c init_b_to_a.c main.c \
				ope_push.c ope_reverse_rotate.c ope_rotate.c ope_swap.c \
				sort_stacks.c sort.c stack_init.c stack_utils.c stop.c
SRCS		=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

################################################################################
## RULES

all: libft $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_INC) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

libft:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libft
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 19:32:42 by tbrunier          #+#    #+#              #
#    Updated: 2024/07/17 19:32:42 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME = pipex.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= include/
SRC_PATH	= src/
OBJ_PATH	= obj/

################################################################################
## SOURCES

SRC_FILES	=	
SRCS		=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

################################################################################
## RULES

all : $(NAME) libft

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) -o $@ -c $< -Llibft -lft $(CFLAGS) -I $(INCLUDE)
$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

libft:
	make -C ./src/libft

clean:
	rm -rf $(OBJ_PATH)
	make -C ./src/libft clean
	
fclean: clean
	rm -f $(NAME)
	rm -f ./src/libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft

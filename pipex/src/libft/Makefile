# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:10:24 by tbrunier          #+#    #+#              #
#    Updated: 2024/07/03 13:10:24 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INC_PATH	= .
SRC_PATH	= .
OBJ_PATH	= obj/

################################################################################
## SOURCES

SRC_FILES	=	ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strlen.c \
				ft_printf.c ft_print_unsigned.c

SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

################################################################################
## RULES

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<
$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

fclean : clean
	rm -rf $(NAME)
clean :
	rm -rf $(OBJ_PATH)

re : fclean all

.PHONY : all fclean clean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 16:49:00 by tbrunier          #+#    #+#              #
#    Updated: 2024/10/11 20:11:09 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME		= get_next_line.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INC_PATH	= include/
SRC_PATH	= .
OBJ_PATH	= obj/

################################################################################
## SOURCES

SRC_FILES	= get_next_line_utils.c get_next_line.c

SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

################################################################################
## RULES

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<
$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
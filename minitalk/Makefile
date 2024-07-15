# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:03:52 by tbrunier          #+#    #+#              #
#    Updated: 2024/07/03 13:03:52 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = obj

################################################################################
## SOURCES

SOURCES = server.c client.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

BONUS_SOURCES = server_bonus.c client_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:%.c=$(OBJDIR)/%.o)

################################################################################
## RULES

all: bonus server client 

server: $(OBJDIR)/server.o
	$(CC) -o $@ $< -Llibft -lft

client: $(OBJDIR)/client.o
	$(CC) -o $@ $< -Llibft -lft

bonus: objdir libft server_bonus client_bonus

server_bonus: $(BONUS_OBJECTS)
	$(CC) -o $@ $(OBJDIR)/server_bonus.o -Llibft -lft

client_bonus: $(BONUS_OBJECTS)
	$(CC) -o $@ $(OBJDIR)/client_bonus.o -Llibft -lft

$(OBJDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft:
	make -C libft

clean:
	rm -rf $(OBJDIR)
	make -C libft clean
	
fclean: clean
	rm -f server client server_bonus client_bonus
	rm -f libft/libft.a

re: fclean all

objdir:
	mkdir -p $(OBJDIR)

.PHONY: all clean fclean re bonus libft objdir

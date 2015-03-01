# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/01 11:22:46 by rroignan          #+#    #+#              #
#    Updated: 2015/03/01 20:25:53 by rroignan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

CFLAGS = -Wall -Wextra -Werror

DIRLIB = libft/

SRC = new_al.c ttfe.c pitch.c resolve.c display.c horizontal_fus1.c horizontal_fus2.c vertical_fus1.c vertical_fus2.c init_tab.c

OBJ = $(SRC:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(DIRLIB) && $(MAKE))
	$(CC) -lncurses -L./$(DIRLIB) -lft -o $(NAME) $(OBJ)

%.o: %.c ttfe.h
	$(CC) -c $(CFLAGS) $< -I $(DIRLIB)


clean:
	rm -f $(OBJ)
	@(cd $(DIRLIB) && $(MAKE) $@)

fclean: clean
	rm -f $(NAME)
	@(cd $(DIRLIB) && $(MAKE) $@)

re: fclean all

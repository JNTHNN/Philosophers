# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 10:45:33 by jgasparo          #+#    #+#              #
#    Updated: 2024/02/29 17:20:03 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
		sources/ft_atoi.c \
		sources/threads.c \
		sources/time.c \
		 
OBJ = $(SRC:.c=.o)
LIBS = -lpthread 
TEST = -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

test: 
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(TEST) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

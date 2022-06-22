# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 20:48:14 by apielasz          #+#    #+#              #
#    Updated: 2022/06/22 23:52:54 by apielasz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c \
		srcs/check_if_too_big.c \
		srcs/check_input.c \
		srcs/linked_ops.c \
		srcs/radix.c \
		srcs/sort.c \
		srcs/utils.c \
		operations/pushing.c \
		operations/reversing.c \
		operations/rotating.c \
		operations/swapping.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
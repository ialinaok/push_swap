# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 20:48:14 by apielasz          #+#    #+#              #
#    Updated: 2022/06/24 00:10:42 by apielasz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c \
		srcs/check_if_too_big.c \
		srcs/check_input.c \
		srcs/linked_ops.c \
		srcs/linked_utils.c \
		srcs/main_utils.c \
		srcs/radix.c \
		srcs/sort.c \
		srcs/utils.c \
		operations/pushing.c \
		operations/reversing.c \
		operations/rotating.c \
		operations/swapping.c
OBJS = $(SRCS:.c=.o)

BONUS = bonus/bonus_ops.c \
		bonus/checker.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
		operations/pushing.c \
		operations/reversing.c \
		operations/rotating.c \
		operations/swapping.c \
		srcs/check_if_too_big.c \
		srcs/check_input.c \
		srcs/linked_ops.c \
		srcs/main_utils.c \
		srcs/utils.c
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all bonus clean fclean re
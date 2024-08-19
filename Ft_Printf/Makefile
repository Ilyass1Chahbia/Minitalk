# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 10:08:18 by ilchahbi          #+#    #+#              #
#    Updated: 2023/12/16 13:04:25 by ilchahbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c  ft_putchar.c  ft_putstr.c  ft_putnbr.c  ft_printunsigned.c  ft_printptr.c  ft_printhex.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		ar rc $@ $^

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJ)
	
fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean
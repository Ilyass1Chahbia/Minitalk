# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 13:29:31 by ilchahbi          #+#    #+#              #
#    Updated: 2024/05/15 13:18:30 by ilchahbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
PRINTF = ./Ft_Printf/libftprintf.a
PATH_PRINTF = ./Ft_Printf
SRCC = client.c
SRCS = server.c
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o} 
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
SRC = Ft_Printf/ft_printf.c  Ft_Printf/ft_putchar.c Ft_Printf/ft_printf.h Ft_Printf/ft_putstr.c  Ft_Printf/ft_putnbr.c  Ft_Printf/ft_printunsigned.c  Ft_Printf/ft_printptr.c  Ft_Printf/ft_printhex.c

all: $(PRINTF) $(NAMEC) $(NAMES) 

$(NAMEC): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) $(PRINTF) -o $(NAMEC)

$(PRINTF) :
	make -C $(PATH_PRINTF)

$(NAMES): $(OBJS) | $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(PRINTF) -o $(NAMES)

%.o : %.c minitalk.h Ft_Printf/ft_printf.h
		${CC} ${CFLAGS} -c $<

clean:
	make clean -C Ft_Printf
	rm -rf $(OBJC)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C Ft_Printf
	rm -rf $(NAMEC)
	rm -rf $(NAMES)

re: fclean all

.PHONY: clean